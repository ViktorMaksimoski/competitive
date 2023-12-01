#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
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

vector<vector<int> > graph;
vector<int> depth;

void dfs(int u, int p) {
    for(int &v : graph[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int32_t main() {
    setIO();

    int n;
    cin >> n;

    if(n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    graph.resize(n+1);
    depth.resize(n+1);
    for(int i=0; i<n+1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    int best = 0;
    for(int i=1; i<=n; i++)
        if(depth[i] > depth[best])
            best = i;

    fill(all(depth), 0);
    dfs(best, 0);

    best = 0;
    for(int i=1; i<=n; i++)
        if(depth[i] > depth[best])
            best = i;
        
    cout << 3 * depth[best] << '\n';
    return 0;
}