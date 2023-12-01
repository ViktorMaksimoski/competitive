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

struct DSU {
    int n;
    vector<int> par, size;

    DSU(int _n) {
        n = _n + 1;
        par.resize(n+1);
        size.resize(n+1);
        for(int i=1; i<=n; i++) par[i] = i, size[i] = 1;
    }

    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    } 

    bool uni(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return false;
        if(size[a] < size[b]) swap(a, b);

        size[a] += size[b];
        par[b] = a;

        return true;
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;

    vector<Edge> edges(n-1);
    for(Edge &e : edges) cin >> e.a >> e.b >> e.w;
    sort(all(edges));

    DSU dsu(n);
    ll res = 0;
    vector<ll> ans(q);
    vector<pii> queries(q);

    for(int i=0; i<q; i++) {
        cin >> queries[i].second;
        queries[i].first = i;
    }

    sort(all(queries), [&](pii &a, pii &b) {
        return a.second < b.second;
    });

    int j=0;
    for(int i=0; i<q; i++) {
        while(j < n-1 && edges[j].w <= queries[i].second) {
            res += 1ll * dsu.getSize(edges[j].a) * dsu.getSize(edges[j].b);
            dsu.uni(edges[j].a, edges[j].b);
            j++;
        }

        ans[queries[i].first] = res;
    }

    for(ll &x : ans) cout << x << " ";
    return 0;
}