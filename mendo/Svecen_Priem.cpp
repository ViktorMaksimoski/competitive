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
vector<vector<ll> > dp;
vector<int> val;
 
void dfs(int u, int p) {
    dp[u][0] = 0;
    dp[u][1] = val[u];
 
    for(int &v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[u][1] += dp[v][0];
    }
 
    for(int &v : graph[u]) {
        if(v == p) continue;
        dp[u][0] += max(dp[v][1], dp[v][0]);
    }
}
 
int32_t main() {
    setIO();
 
    int n;
    cin >> n;
    graph.resize(n+1);
    dp.resize(n+1, vector<ll>(2, 0));
    val.resize(n+1);
    cin >> val[1];
 
    for(int i=2; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        val[i] = a;
        graph[i].pb(b+1);
        graph[b+1].pb(i);
    }
 
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << '\n';
    return 0;
}