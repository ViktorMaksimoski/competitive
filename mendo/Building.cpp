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

void solve() {
    int n, l;
    cin >> n >> l;

    vector<int> p(n+1), h(n+1);
    for(int i=1; i<=n; i++) cin >> p[i] >> h[i];

    vector<vector<int> > table(n+2, vector<int>(LOG));
    vector<int> log_dp(n+2);
    log_dp[1] = 0;
    for(int i=2; i<=n+1; i++) log_dp[i] = log_dp[i/2] + 1;
    for(int i=0; i<=n; i++) table[i][0] = h[i];

    for(int j=1; j<LOG; j++)
        for(int i=0; i+(1<<j)-1<n+1; i++)
            table[i][j] = max(table[i][j-1], table[i+(1<<(j-1))][j-1]);

    auto query = [&](int a, int b) {
        if(a > b) return 0;
        int len = b - a + 1;
        int k = log_dp[len];

        return max(table[a][k], table[b-(1<<k)+1][k]);
    };

    vector<pii> dp(n+1);
    for(int i=1; i<=n; i++) dp[i].second = 1e9;
    int lp = 1;

    for(int i=1; i<=n; i++) {
        while(lp < i && p[i] - p[lp] > l) lp++;
        dp[i] = dp[i-1];

        if(i > lp && query(lp, i-1) == h[i]) {
            if(dp[i].first < (i - lp + 1) + dp[lp-1].first) {
                dp[i].first = (i - lp + 1) + dp[lp-1].first;
                dp[i].second = dp[lp-1].second + 1;
            } else if(dp[i].first < (i - lp + 1) + dp[lp-1].first) {
                dp[i].second = min(dp[i].second, dp[lp-1].second + 1);
            }
        }
    }

    cout << dp[n].first << " " << dp[n].second << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}