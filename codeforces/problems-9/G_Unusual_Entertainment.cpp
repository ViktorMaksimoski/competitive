#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
//#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct SegTree {
    int n, lp, rp;
    vector<int> v;
    vector<vector<int> > tree;

    SegTree(vector<int> &_v) {
        v = _v;
        n = sz(v);
        tree.resize(4*n+5);
        build(1, 0, n-1);
    }

    void build(int u, int tl, int tr) {
        if(tl == tr) {
            tree[u] = {v[tl]};
        } else {
            int tm = (tl + tr) / 2;

            build(2*u, tl, tm);
            build(2*u+1, tm+1, tr);
            sort(all(tree[2*u]));
            sort(all(tree[2*u+1]));
            merge(all(tree[2*u]), all(tree[2*u+1]), back_inserter(tree[u]));
        }
    }

    int query(int u, int tl, int tr, int l, int r) {
        if(l > r || tl > r || l > tr) return 0;

        if(l <= tl && tr <= r)
            return lower_bound(all(tree[u]), rp) - lower_bound(all(tree[u]), lp);

        int tm = (tl + tr) / 2;
        return query(2*u, tl, tm, l, r)
        + query(2*u+1, tm+1, tr, l, r);
    }

    int query(int l, int r, int x, int y) {
        lp = x;
        rp = y;
        return query(1, 0, n-1, l, r);
    }
};

vector<vector<int> > graph;
vector<int> in, out;
int timer = 0;

void dfs(int u, int p) {
    in[u] = timer++;

    for(int &v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
    }

    out[u] = timer;
}

void solve() {
    int n, q;
    cin >> n >> q;
    graph.clear();
    in.clear();
    out.clear();
    graph.resize(n+5);
    in.resize(n+5);
    out.resize(n+5);

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    vector<int> p(n+5);
    for(int i=1; i<=n; i++) cin >> p[i];
    for(int i=1; i<=n; i++) p[i] = in[p[i]];

    SegTree tree(p);
    while(q--) {
        int l, r, x;
        cin >> l >> r >> x;

        cout << (tree.query(l, r, in[x], out[x]) ? "YES" : "NO") << '\n';
    }

    cout << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}