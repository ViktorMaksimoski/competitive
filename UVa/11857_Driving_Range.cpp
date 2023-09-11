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

struct Edge {
    int a, b, w;

    bool operator<(Edge &e) {
        return w < e.w;
    }
};

struct DSU {
    int n, comp;
    vector<int> par;
    vector<int> size;

    DSU(int &_n) {
        n = _n;
        comp = n;
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

    int same_set(int a, int b) {
        a = find(a);
        b = find(b);
        return (a == b);
    }
};

int32_t main() {
    setIO();

    int n, m;

    while(true) {
        cin >> n >> m;
        if(!n && !m) break;

        vector<Edge> edges(m);
        DSU dsu(n);

        for(int i=0; i<m; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            edges[i] = Edge{a, b, w};
        }

        int last = 0;
        sort(all(edges));

        for(Edge &e : edges) {
            if(dsu.same_set(e.a, e.b)) continue;
            last = e.w;
            dsu.uni(e.a, e.b);
        }

        if(dsu.getComp() > 1) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        cout << last << '\n';
    }

    return 0;
}