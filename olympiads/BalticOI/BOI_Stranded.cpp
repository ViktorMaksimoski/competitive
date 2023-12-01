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
    int n, comp;
    vector<int> par, mx;
    vector<ll> total;
    vector<bool> bad;

    DSU(int &_n, vector<int> &_v) {
        n = _n + 1;
        comp = _n;
        par.resize(n+1);
        mx.resize(n+1);
        total.resize(n+1);
        bad.resize(n+1);
        for(int i=1; i<=n; i++) {
            par[i] = i;
            bad[i] = 0;
            total[i] = mx[i] = _v[i];
        }
    }

    int find(int x) {
        if(x == par[x]) return x;
        int p = find(par[x]);
        if(bad[par[x]]) bad[x] = 1;
        return par[x] = p;
    }

    bool uni(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return false;
        if(mx[a] < mx[b]) swap(a, b);
        if(mx[a] > total[b]) bad[b] = 1;
        par[b] = a;
        total[a] += total[b];
        comp--;
        
        return true;
    }

    bool check(int a) {
        find(a);
        return bad[a];
    }

    int getComp() { return comp; }
};

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;
    vector<int> val(n+1);
    for(int i=1; i<=n; i++) cin >> val[i];

    vector<Edge> edges(m);
    for(Edge &e : edges) {
        cin >> e.a >> e.b;
        e.w = max(val[e.a], val[e.b]);
    }

    DSU dsu(n, val);
    sort(all(edges));
    for(Edge &e : edges) dsu.uni(e.a, e.b);

    //cout << "COMPS: " << dsu.getComp() << '\n';
    for(int i=1; i<=n; i++)
        cout << !dsu.check(i);
    return 0;
}