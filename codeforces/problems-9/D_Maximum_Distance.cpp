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
    vector<int> sp;

    DSU(int _n) {
        n = _n + 1;
        par.resize(n+1);
        size.resize(n+1);
        sp.resize(n+1);
        for(int i=1; i<=n; i++) par[i] = i, size[i] = 1, sp[i] = 0;
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
        sp[a] += sp[b];
        par[b] = a;

        return true;
    }

    bool same_set(int a, int b) {
        return find(a) == find(b);
    }

    int getSize(int x) {
        return size[find(x)];
    }

    void set(int x) {
        sp[x] = 1;
    }

    int check(int x) {
        return sp[find(x)];
    }
};

int32_t main() {
    setIO();

    int n, m, k;
    cin >> n >> m >> k;

    DSU dsu(n);
    vector<bool> special(n+1, 0);
    for(int i=0; i<k; i++) {
        int x;
        cin >> x;
        special[x] = 1;
        dsu.set(x);
    }

    vector<Edge> edges(m);
    for(Edge &e : edges) cin >> e.a >> e.b >> e.w;
    sort(all(edges));

    int ans = 0;

    for(Edge &e : edges) {
        dsu.uni(e.a, e.b);
        if(dsu.check(e.a) == k) { 
            ans = e.w;
            break;
        }
    }

    for(int i=0; i<k; i++) cout << ans << " ";
    return 0;
}