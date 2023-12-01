#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define int long long

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

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];

    vector<vector<ll> > dp(n+1, vector<ll>(35, -1e18));
    dp[0][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=32; j++) {
            dp[i][j] = dp[i-1][j] + v[i] / (1ll << j) - k;
            if(j > 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + v[i] / (1ll << j));
        }
    }

    ll ans = 0;
    for(int i=1; i<=n; i++)
        for(int j=0; j<=32; j++) ans = max(ans, dp[i][j]);
    cout << ans << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}