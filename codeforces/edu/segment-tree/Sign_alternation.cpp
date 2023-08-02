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
#include <climits>

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
    vector<int> v;
    vector<ll> tree;

    SegTree(vector<int> const &v) {
        this->n = sz(v);
        this->v = v;
        tree.resize(4*n, 0);
        build(1, 0, n-1);
    }

    void build(int u, int l, int r) {
        if(l == r) {
            tree[u] = v[l];
        } else {
            int m = (l + r) / 2;
            build(2*u, l, m);
            build(2*u+1, m+1, r);
            tree[u] = tree[2*u] + tree[2*u+1];
        }
    }

    ll query(int u, int tl, int tr, int l, int r) {
        if(l > r) return 0;
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return query(2*u, tl, tm, l, min(r, tm)) 
        + query(2*u+1, tm+1, tr, max(tm+1, l), r);
    }

    void update(int u, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            tree[u] = val;
            v[tl] = val;
        } else {
            int tm = (tl + tr) / 2;
            if(tl <= pos && pos <= tm)
                update(2*u, tl, tm, pos, val);
            else
                update(2*u+1, tm+1, tr, pos, val);
            tree[u] = tree[2*u] + tree[2*u+1];
        }
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }

    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    int get(int u) {
        return tree[u];
    }
};

int32_t main() {
    setIO();

    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> even, odd;

    for(int i=0; i<n; i++) {
        cin >> v[i];
        if(i % 2 == 0) even.pb(v[i]);
        else odd.pb(v[i]);
    }

    SegTree tree1(even), tree2(odd);
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;

        if(t == 0) {
            int a, b;
            cin >> a >> b;
            a--;
            if(a & 1) {
                tree2.update(a/2, b);
            } else {
                tree1.update(a/2, b);
            }
        } else {
            int a, b;
            cin >> a >> b;
            a--, b--;

            ll sum1=0, sum2=0;

            if(a & 1) {
                sum1 = tree2.query(a/2, (b-1)/2);
                sum2 = tree1.query((a+1)/2, b/2);
            } else {
                sum1 = tree1.query(a/2, b/2);
                sum2 = tree2.query(a/2, (b-1)/2);
            }

            cout << sum1 - sum2 << '\n';
        }
    }

    return 0;
}