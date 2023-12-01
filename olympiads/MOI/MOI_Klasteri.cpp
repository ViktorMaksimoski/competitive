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

int n, o, s;
vector<set<int> > deg;

struct DSU {
    int n;
    vector<int> par, size;

    DSU(int &_n) {
        n = _n+1;
        par.resize(n+1);
        size.resize(n+1);
        for(int i=1; i<=n; i++) par[i] = i, size[i] = 1;
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
        par[b] = a;
        size[a] += size[b];

        return true;
    }

    int getSize(int a) {
        return size[find(a)];
    }

    bool same_set(int a, int b) {
        return find(a) == find(b);
    }
};

int32_t main() {
    setIO();

    cin >> n >> o;
    deg.resize(n+1);

    DSU dsu(n);

    for(int i=0; i<o; i++) {
        int a, b;
        cin >> a >> b;
        dsu.uni(a, b);
        deg[a].insert(b);
        deg[b].insert(a);
    }

    cin >> s;
    for(int i=0; i<s; i++) {
        int a, b;
        cin >> a >> b;
        if(dsu.same_set(a, b)) {
            deg[a].insert(b);
            deg[b].insert(a);
        }
    }

    for(int i=1; i<=n; i++)
        cout << dsu.getSize(i) - deg[i].size() - 1 << '\n';
    return 0;   
}