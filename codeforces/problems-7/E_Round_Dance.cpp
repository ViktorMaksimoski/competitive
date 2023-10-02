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

int n;
int comp = 0;
int cycles = 0;
bool can = false;
vector<set<int> > graph;
vector<bool> vis;
vector<int> to_comp;

void dfs(int u, int p) {
    vis[u] = 1;

    for(const int &v : graph[u]) {
        if(!vis[v]) {
            dfs(v, u);
        } else if(v != p) {
            if(!can) cycles++, can = 1;
        }
    }
}

void solve() {
    cin >> n;
    graph.clear();
    graph.resize(n+1);
    vis.clear();
    vis.resize(n+1, 0);
    to_comp.clear();
    to_comp.resize(n+1, -1);
    comp = 0, cycles = 0;

    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        graph[i].insert(x);
        graph[x].insert(i);
    }

    for(int i=1; i<=n; i++) {
        if(vis[i]) continue;
        comp++;
        can = 0;
        dfs(i, -1);
    }

    cout << cycles + (cycles != comp) << " " << comp << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}