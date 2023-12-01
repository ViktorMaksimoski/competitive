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

int n, k;
vector<vector<int> > graph;
vector<vector<ll> > dp;
vector<ll> sub;
vector<int> val;

void dfs(int u, int p) {
    sub[u] = val[u];
    for(int &v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
        sub[u] += sub[v];
    }

    for(int &v : graph[u]) {
        if(v == p) continue;
        
        for(int i=k; i>=0; i--) {
            dp[u][i] = dp[u][i] + dp[v][0];
            for(int j=i; j>=1; j--) {
                dp[u][i] = max(dp[u][i], dp[u][i-j] + dp[v][j]);
            }
        }
    }

    dp[u][0] = sub[u];
    for(int i=1; i<=k; i++)
        dp[u][i] = max({ dp[u][0], 0ll, dp[u][i] + val[u] });
}

int32_t main() {
    setIO();

    cin >> n >> k;
    graph.resize(n+1);
    sub.resize(n+1);
    val.resize(n+1);
    dp.resize(n+1, vector<ll>(k+1, 0));

    for(int i=1; i<=n; i++) cin >> val[i];

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    cout << dp[1][k] << '\n';
    return 0;
}