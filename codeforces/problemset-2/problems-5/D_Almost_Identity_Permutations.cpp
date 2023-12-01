#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
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

int32_t main() {
    setIO();

    int n, k;
    cin >> n >> k;

    vector<vector<ll> > dp(n+1, vector<ll>(k+1, 0));
    for(int i=0; i<=n; i++) dp[i][0] = 1;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=k; j++)
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];

    ll ans = 1, curr = 1;

    for(int i=1; i<=k; i++) {
        curr = (curr * i) + ((i & 1) ? -1 : 1);
        ans += (dp[n][i] * curr);
    }

    cout << ans << '\n';
    return 0;
}