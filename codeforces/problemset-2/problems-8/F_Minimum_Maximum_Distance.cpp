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
vector<int> depth;

void dfs(int u, int p) {
    for(int &v : graph[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    graph.clear();
    graph.resize(n+1);
    depth.clear();
    depth.resize(n+1);

    vector<int> v(k);
    for(int &x : v) cin >> x;

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    int a = 0;
    for(int &x : v)
        if(depth[x] > depth[a])
            a = x;

    depth[a] = 0;
    dfs(a, 0);

    int ans = 0;
    for(int &x : v)
        ans = max(ans, depth[x]);
    cout << (ans + 1) / 2 << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}