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

vector<vector<int> > graph;
vector<bool> vis;
vector<bool> ap;
map<pii, int> comp;
vector<int> in, low;
int timer = 0;

void dfs(int u, int p) {
    vis[u] = 1;
    in[u] = low[u] = timer++;
    int ch = 0;

    for(int &v : graph[u]) {
        if(v == p) continue;
        if(vis[v]) {
            low[u] = min(low[u], in[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= in[u] && p) ap[u] = 1;
            ch++;
        }
    }

    if(!p && ch > 1) ap[u] = 1;
}

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;
    graph.resize(n+1);
    vis.resize(n+1);
    ap.resize(n+1);
    in.resize(n+1);
    low.resize(n+1);
    vector<pii> edges(m);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edges[i] = {a, b};
        comp[{a, b}] = comp[{b, a}] = i;
    }

    dfs(1, 0);
    int ans = 0;
    for(int i=1; i<=n; i++) ans += ap[i];
    cout << ans << '\n';
    for(int i=1; i<=n; i++)
        if(ap[i]) cout << i << " ";
    return 0;
}