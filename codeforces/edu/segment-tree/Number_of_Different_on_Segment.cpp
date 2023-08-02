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
using Node = array<int, 41>;

const int mod = 1e9 + 7;
const int LOG = 20;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

Node empty() {
    Node res;
    for(int i=0; i<41; i++)
        res[i] = 0;
    return res;
}

struct SegTree {
    int n;
    vector<int> v;
    vector<Node> tree;

    SegTree(vector<int> const &v) {
        n = sz(v);
        this->v = v;
        tree.resize(4*n+10);
        build(1, 0, n-1);
    }

    Node combine(Node a, Node b) {
        Node res;
        for(int i=0; i<41; i++)
            res[i] = a[i] + b[i];
        return res;
    }

    void build(int u, int l, int r) {
        if(l == r) {
            for(int i=0; i<41; i++)
                tree[u][i] = 0;
            tree[u][v[l]] = 1;
        } else {
            int m = (l + r) / 2;
            build(2*u, l, m);
            build(2*u+1, m+1, r);
            tree[u] = combine(tree[2*u], tree[2*u+1]);
        }
    }

    void update(int u, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            for(int i=0; i<41; i++)
                tree[u][i] = 0;
            tree[u][val] = 1;
        } else {
            int tm = (tl + tr) / 2;
            if(pos <= tm)
                update(2*u, tl, tm, pos, val);
            else
                update(2*u+1, tm+1, tr, pos, val);
            tree[u] = combine(tree[2*u], tree[2*u+1]);
        }
    }

    Node query(int u, int tl, int tr, int l, int r) {
        if(tl > r || l > tr) return empty();
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return combine(
            query(2*u, tl, tm, l, r),
            query(2*u+1, tm+1, tr, l, r)
        );
    }

    Node query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }
};

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    SegTree tree(v);
    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;

        if(t == 1) {
            Node res = tree.query(a-1, b-1);
            int ans = 0;
            for(int &x : res)
                ans += (x > 0);
            cout << ans << '\n';
        } else {
            tree.update(a-1, b);
        }
    }

    return 0;
}