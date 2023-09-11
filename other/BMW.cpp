#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define int long long

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

struct Edge {
    int a, b, w;

    bool operator<(Edge &e) {
        return w > e.w;
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

    bool same_set(int a, int b) {
        a = find(a);
        b = find(b);
        return (a == b);
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
};

void solve() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    vector<Edge> edges(m);

    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = Edge{a, b, w};
    }

    sort(all(edges));
    int ans = 0;

    for(Edge &e : edges) {
        if(dsu.same_set(e.a, e.b)) continue;
        ans = e.w;
        dsu.uni(e.a, e.b);
        if(dsu.same_set(1, n)) {
            cout << ans << '\n';
            return ;
        }
    }

    cout << -1 << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}