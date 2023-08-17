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

vector<vector<int> > graph[2];
vector<bool> vis;
vector<int> id, s;

void dfs(int u, int t, int x=0) {
    vis[u] = true;
    for(int &v : graph[t][u]) {
        if(vis[v]) continue;
        dfs(v, t, x);
    }

    s.pb(u);
    if(t == 1) id[u] = x;
}

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;
    for(int i=0; i<2; i++) graph[i].resize(n+1);
    vis.resize(n+1, 0);
    id.resize(n+1, 0);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[0][a].push_back(b);
        graph[1][b].push_back(a);
    }

    for(int i=1; i<=n; i++)
        if(!vis[i]) dfs(i, 0);

    fill(all(vis), 0);
    int cmp = 0;
    for(int i=n-1; i>=0; i--) {
        if(!vis[s[i]]) {
            cmp++;
            dfs(s[i], 1, cmp);
        }
    }

    vector<int> occ(n+1);
    for(int i=1; i<=n; i++) occ[id[i]]++;

    cout << cmp << '\n';
    int mx = 0, mn = 1e9;
    for(int i=1; i<=n; i++) {
        mx = max(mx, occ[i]);
        if(occ[i]) mn = min(mn, occ[i]);
    }
    cout << mn << " " << mx << '\n';
    return 0;
}