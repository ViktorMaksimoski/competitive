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
using Node = array<int, 3>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct DSU {
    int n;
    int comp;
    vector<int> par, size;

    DSU(int &_n) {
        n = _n + 1;
        comp = _n;
        par.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++) par[i] = i;
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

        comp--;
        par[b] = a;
        size[a] += size[b];

        return 1;
    }

    inline bool same_set(int a, int b) {
        return find(a) == find(b);
    }
};

int32_t main() {
    setIO();

    int n;
    cin >> n;
    DSU dsu(n);

    vector<vector<int> > graph(n+1);
    vector<Node> edges;

    for(int i=1; i<n; i++) {
        for(int j=0; j<n-i; j++) {
            int x;
            cin >> x;
            edges.push_back({ x, i, i+j+1 });
        }
    }

    sort(all(edges));
    vector<bool> vis(n+1, false);
    for(int i=0; i<edges.size(); i++) {
        if(dsu.same_set(edges[i][1], edges[i][2])) continue;
        graph[edges[i][1]].push_back(edges[i][2]);
        graph[edges[i][2]].push_back(edges[i][1]);
        dsu.uni(edges[i][1], edges[i][2]);
    }

    for(int i=1; i<=n; i++) {
        cout << graph[i].size() << " ";
        sort(all(graph[i]));
        for(int &x : graph[i]) cout << x << " ";
        cout << '\n';
    }

    return 0;
}