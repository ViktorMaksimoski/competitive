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

int32_t main() {
    setIO();

    int n;
    cin >> n;

    vector<double> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];

    vector<vector<double> > dp(n+1, vector<double>(n+1, 0));
    for(int i=0; i<=n; i++) dp[i][0] = 1;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            dp[i][j] = dp[i-1][j-1] * v[i] + dp[i-1][j] * (1 - v[i]);

    cout << setprecision(10) << fixed << dp[n][n/2+1] << '\n';
    return 0;
}