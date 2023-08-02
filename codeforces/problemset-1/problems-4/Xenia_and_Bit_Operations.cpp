#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <stack>
#include <cstring>
#include <chrono>
#include <random>
#include <numeric>
#include <bitset>
#include <array>
#include <functional>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << ": " << x << '\n'
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct SegTree {
    int n;
    int levels;
    vector<int> v;
    vector<ll> tree;

    SegTree(vector<int> const &v, int levels) {
        this->n = sz(v);
        this->v = v;
        this->levels = levels;
        tree.resize(4*n+5, 0);
        build(1, 0, n-1, 0);
    }

    void build(int u, int l, int r, int d) {
        if(l == r) {
            tree[u] = v[l];
        } else {
            int m = (l + r) / 2;
            build(2*u, l, m, d+1);
            build(2*u+1, m+1, r, d+1);
            if(d % 2 == levels % 2)
                tree[u] = tree[2*u] ^ tree[2*u+1]; 
            else
                tree[u] = tree[2*u] | tree[2*u+1];
        }
    }

    void update(int u, int tl, int tr, int pos, int val, int d) {
        if(tl == tr) {
            tree[u] = val;
        } else {
            int tm = (tl + tr) / 2;

            if(pos <= tm)
                update(2*u, tl, tm, pos, val, d+1);
            else
                update(2*u+1, tm+1, tr, pos, val, d+1);

            if(d % 2 == levels % 2)
                tree[u] = tree[2*u] ^ tree[2*u+1]; 
            else
                tree[u] = tree[2*u] | tree[2*u+1];
        }
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val, 0);
    }

    ll get(int u) {
        return tree[u];
    }
};

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;

    vector<int> v(1 << n);
    for(int &x : v) cin >> x;

    SegTree tree(v, n);
    while(q--) {
        int a, b;
        cin >> a >> b;
        tree.update(a-1, b);
        cout << tree.get(1) << '\n';
    }

    return 0;
}