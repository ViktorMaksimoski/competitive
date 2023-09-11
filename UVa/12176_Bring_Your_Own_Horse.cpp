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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<vector<pii> > graph;
vector<vector<int> > up, mx;
vector<int> depth;

struct Edge {
    int a;
    int b;
    int w;

    bool operator<(Edge &e) {
        return w < e.w;
    }
};

struct DSU {
    int n;
    int comp;
    vector<int> par;
    vector<int> size;

    DSU(int &_n) {
        n = _n + 1;
        comp = _n;
        par.resize(n);
        size.resize(n);
        for(int i=0; i<n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int getComp() {
        return comp;
    }

    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    bool uni(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return false;
        if(size[a] < size[b]) swap(a, b);

        size[a] += size[b];
        par[b] = a;
        comp--;

        return true;
    }

    bool same_set(int a, int b) {
        a = find(a);
        b = find(b);
        return (a == b);
    }
};

void reset(int n) {
    graph.clear();
    graph.resize(n+1);
    depth.clear();
    depth.resize(n+1);
    up.clear();
    up.resize(n+1, vector<int>(LOG));
    mx.clear();
    mx.resize(n+1, vector<int>(LOG, 0));
}

void dfs(int u, int p) {
    for(int j=1; j<LOG; j++) {
        up[u][j] = up[ up[u][j-1] ][j-1];
        mx[u][j] = max(mx[u][j-1], mx[ up[u][j-1] ][j-1]);
    }

    for(pii &next : graph[u]) {
        int v = next.first;
        int d = next.second;
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        mx[v][0] = d;
        dfs(v, u);
    }
}

int get_mx(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    int ans = 0;
    int d = depth[a] - depth[b];
    for(int j=LOG-1; j>=0; j--) {
        if(d & (1 << j)) {
            ans = max(ans, mx[a][j]);
            a = up[a][j];
        }
    }

    if(a == b) return ans;

    for(int j=LOG-1; j>=0; j--) {
        if(up[a][j] != up[b][j]) {
            ans = max(ans, mx[a][j]);
            ans = max(ans, mx[b][j]);
            a = up[a][j];
            b = up[b][j];
        }
    }

    return max({ ans, mx[a][0], mx[b][0] });
}

void solve() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    vector<Edge> edges(m);
    for(Edge &e : edges) cin >> e.a >> e.b >> e.w;

    sort(all(edges));
    reset(n+1);
    for(Edge &e : edges) {
        if(dsu.same_set(e.a, e.b)) continue;
        dsu.uni(e.a, e.b);
        graph[e.a].push_back({ e.b, e.w });
        graph[e.b].push_back({ e.a, e.w });
    }

    //precompute up and mx (binary lifting)
    dfs(1, 0);

    // for(int i=1; i<=n; i++) {
    //     cout << i << ": ";
    //     for(auto &v : graph[i]) cout << v.first << ", ";
    //     cout << '\n';
    // }

    int q;
    cin >> q;

    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << get_mx(a, b) << '\n';
    }

    cout << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;

    for(int i=1; i<=t; i++) {
        cout << "Case " << i << '\n';
        solve();
    }

    return 0;
}