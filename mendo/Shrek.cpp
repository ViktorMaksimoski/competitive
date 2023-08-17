#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<vector<ll>> dp(k+1, vector<ll>(n+1));

    for(int i=1; i<=n; i++)
        dp[1][i] = (i <= m);

    for(int i=2; i<=k; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=min(j, m); k++)
                dp[i][j] += dp[i-1][j-k];

    cout << dp[k][n] << '\n';
    return 0;
}