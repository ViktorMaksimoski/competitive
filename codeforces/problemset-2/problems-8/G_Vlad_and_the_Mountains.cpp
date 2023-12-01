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

struct Edge {
    int a, b, w;
    bool operator<(Edge &e) {
        return w < e.w;
    }
};

struct Query {
    int id, a, b, w;
    bool operator<(Query &e) {
        return w < e.w;
    }
};

struct DSU {
    int n;
    vector<int> par;
    vector<int> size;

    DSU(int &_n) {
        n = _n + 1;
        par.resize(n+1);
        for(int i=0; i<n; i++) par[i] = i;
        size.resize(n+1, 1);
    }

    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    bool uni(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return 0;
        if(size[a] < size[b]) swap(a, b);

        size[a] += size[b];
        par[b] = a;

        return 1;
    }

    bool same_set(int a, int b) {
        a = find(a);
        b = find(b);
        return a == b;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> val(n+1);
    for(int i=1; i<=n; i++) cin >> val[i];

    vector<Edge> edges(m);

    for(Edge &e : edges) {
        cin >> e.a >> e.b;
        e.w = max(val[e.a], val[e.b]);
    }

    sort(all(edges));

    int q;
    cin >> q;

    vector<bool> ans(q, 0);
    vector<Query> queries(q);

    for(int i=0; i<q; i++) {
        int a, b, e;
        cin >> a >> b >> e;
        queries[i] = { i, a, b, val[a] + e };
    }

    sort(all(queries));

    int pos = 0;
    DSU dsu(n);

    for(int i=0; i<q; i++) {
        for(; pos<m; pos++) {
            if(edges[pos].w > queries[i].w) break;
            dsu.uni(edges[pos].a, edges[pos].b);
        }
        ans[queries[i].id] = dsu.same_set(queries[i].a, queries[i].b); 
    }

    for(int i=0; i<q; i++)
        cout << (ans[i] ? "YES" : "NO") << '\n';
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