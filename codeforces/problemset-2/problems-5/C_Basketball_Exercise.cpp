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

int32_t main() {
    setIO();

    int n;
    cin >> n;
    int v[2][n];
    for(int i=0; i<2; i++)
        for(int j=0; j<n; j++)
            cin >> v[i][j];

    vector<vector<ll> > dp(n, vector<ll>(2, 0));
    dp[0][0] = v[0][0];
    dp[0][1] = v[1][0];

    for(int i=1; i<n; i++) {
        dp[i][0] = dp[i-1][1] + v[0][i];
        dp[i][1] = dp[i-1][0] + v[1][i];

        if(i > 1) {
            dp[i][0] = max(dp[i][0], max(dp[i-2][0], dp[i-2][1]) + v[0][i]);
            dp[i][1] = max(dp[i][1], max(dp[i-2][0], dp[i-2][1]) + v[1][i]);
        }
    }

    cout << max(dp[n-1][0], dp[n-1][1]) << '\n';
    return 0;
}