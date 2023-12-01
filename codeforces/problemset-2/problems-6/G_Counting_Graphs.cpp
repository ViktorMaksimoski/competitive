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

const int mod = 998244353;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

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

    int getSize(int x) {
        x = find(x);
        return size[x];
    }

    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    bool uni(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return false;
        if(size[a] > size[b]) swap(a, b);

        size[a] += size[b];
        par[b] = a;

        comp--;
        return true;
    }
};

ll exp(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n, s;
    ll ans = 1;
    cin >> n >> s;

    DSU dsu(n);
    vector<Edge> edges(n-1);

    for(int i=0; i<n-1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = Edge{a, b, w};
    }

    sort(all(edges));

    for(Edge &e : edges) {
        ll base = s - e.w + 1;
        ll p = 1ll * dsu.getSize(e.a) * dsu.getSize(e.b) - 1;

        ans *= exp(base, p);
        ans %= mod;

        dsu.uni(e.a, e.b);
    }

    cout << ans % mod << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}