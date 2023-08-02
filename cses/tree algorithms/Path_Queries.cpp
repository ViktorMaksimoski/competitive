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

#define int long long
#define pb push_back
#define eb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair
#define rep(i, a, b) for(int i=a; i<b; i++)
#define repr(i, a, b) for(int i=a; i>=b; i--)

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

vector<vector<int> > graph;
vector<int> euler, in, out, val;
vector<ll> path;
int timer = 0;

void dfs(int u, int p, ll sum = 0) {
   sum += val[u];
   euler[timer] = u;
   in[u] = timer++;

   for(int &v : graph[u]) {
    if(v == p) continue;
    dfs(v, u, sum);
   }

   out[u] = timer;
   path[u] = sum;
}

struct SegTree {
    int n;
    vector<ll> tree;
    vector<ll> lazy;

    SegTree(int n) : n(n), tree(4*n+5, 0), lazy(4*n+5, 0) {}

    void push(int u, int l, int r) {
        if(lazy[u] == 0) return ;
        tree[u] += 1ll * (r - l + 1) * lazy[u];
        if(l != r) {
            lazy[2*u] += lazy[u];
            lazy[2*u+1] += lazy[u];
        }
        lazy[u] = 0;
    }

    void updateLazy(int u, int tl, int tr, int l, int r, ll val) {
        push(u, tl, tr);
        if(tl > tr || l > tr || tl > r) return ;

        if(l <= tl && tr <= r) {
            lazy[u] += val;
            push(u, tl, tr);
            return ;
        }

        int tm = (tl + tr) / 2;
        updateLazy(2*u, tl, tm, l, r, val);
        updateLazy(2*u+1, tm+1, tr, l, r, val);
        tree[u] = tree[2*u] + tree[2*u+1];
    }

    void updateSingle(int u, int tl, int tr, int pos, ll val) {
        if(tl == tr) {
            tree[u] += val;
        } else {
            int tm = (tl + tr) / 2;
            if(pos <= tm)
                updateSingle(2*u, tl, tm, pos, val);
            else
                updateSingle(2*u+1, tm+1, tr, pos, val);
            tree[u] = tree[2*u] + tree[2*u+1];
        }
    }

    ll query(int u, int tl, int tr, int l, int r) {
        if(tl > r || l > tr) return 0;
        push(u, tl, tr);

        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return query(2*u, tl, tm, l, r) +
        query(2*u+1, tm+1, tr, l, r);
    }

    void updateLazy(int l, int r, int val) {
        updateLazy(1, 0, n-1, l, r, val);
    }

    void updateSingle(int pos, int val) {
        updateSingle(1, 0, n-1, pos, val);
    }

    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

};

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;

    graph.resize(n+1);
    euler.resize(n, 0);
    in.resize(n+1, 0);
    out.resize(n+1, 0);
    val.resize(n+1, 0);
    path.resize(n+1, 0);

    for(int i=1; i<=n; i++) cin >> val[i];

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    SegTree tree(n+1);
    for(int &x : euler) tree.updateSingle(in[x], path[x]);
    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int a;
            ll b;
            cin >> a >> b;
            ll x =  b - val[a];
            val[a] = b;
            tree.updateLazy(in[a], out[a] - 1, x);
        } else {
            int a;
            cin >> a;
            cout << tree.query(in[a], in[a]) << '\n';
        }
    }

    return 0;
}