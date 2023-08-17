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

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

int32_t main() {
    setIO();
    setUSA("time");

    int n, m, c;
    ll ans = 0;
    cin >> n >> m >> c;

    vector<int> v(n+1);
    for(int i=1; i<=n; i++)
        cin >> v[i];

    vector<vector<int> > graph(n+1);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vector<vector<ll> > dp(n+1, vector<ll>(1005, -1));
    dp[1][0] = 0;
    for(int d=0; d<1001; d++) {
        for(int u=1; u<=n; u++) {
            if(dp[u][d] == -1) continue;
            for(int &x : graph[u]) {
                dp[x][d+1] = max(dp[x][d+1], dp[u][d] + v[x]);
            }
        }
    }

    for(int i=0; i<1001; i++)
        ans = max(ans, dp[1][i] - c * i * i);
    cout << ans << '\n';
    return 0;
}