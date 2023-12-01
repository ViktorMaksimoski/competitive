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
    int a, b;
    ll w;
    bool operator<(Edge & e) {
        return w > e.w;
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
        if(x == par[x]) return par[x];
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

    int getSize(int x) {
        return size[find(x)];
    }
};

ll exp(ll a, ll b, ll m) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return ans;
}

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;

    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];

    vector<Edge> edges;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            ll w = exp(v[i], v[j], m);
            w += exp(v[j], v[i], m);
            w %= m;
            edges.push_back(Edge{ i, j, w });
        }
    }

    sort(all(edges));
    ll ans = 0;
    DSU dsu(n);
    for(Edge &e : edges) {
        if(dsu.uni(e.a, e.b)) ans += e.w;
        if(dsu.getSize(e.a) == n) break;
    }

    cout << ans << '\n';
    return 0;
}