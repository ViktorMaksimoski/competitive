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
vector<int> val;
vector<vector<int> > graph;
vector<int> dp;

void dfs(int u, int p) {
    dp[u] = val[u];
    for(int &v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[u] = min(dp[u], dp[v]);
    }
}

int32_t main() {
    setIO();

    cin >> n;
    graph.resize(n+1);
    val.resize(n+1);
    dp.resize(n+1, 1e9);

    for(int i=1; i<=n; i++) cin >> val[i];

    int root = 0;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if(x == -1) {
            root = i;
            continue;
        }
        graph[i].push_back(x);
        graph[x].push_back(i);
    }

    dfs(root, 0);
    int ans = 0;

    for(int i=1; i<=n; i++)
        ans = max(ans, val[i] - dp[i]);

    cout << ans << '\n';
    return 0;
}