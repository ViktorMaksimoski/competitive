#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, c;
    cin >> n >> c;

    vector<int> a(n), b(n);
    for(int i=1; i<n; i++) cin >> a[i];
    for(int i=1; i<n; i++) cin >> b[i];

    vector<vector<ll> > dp(n, vector<ll>(2, 1e18));

    dp[0][0] = 0;
    dp[0][1] = c;
    cout << 0 << " ";

    for(int i=1; i<n; i++) {
        dp[i][0] = min(dp[i][0], dp[i-1][0] + a[i]);
        dp[i][0] = min(dp[i][0], dp[i-1][1] + a[i]);
        dp[i][1] = min(dp[i][1], dp[i-1][0] + b[i] + c);
        dp[i][1] = min(dp[i][1], dp[i-1][1] + b[i]);
        cout << min(dp[i][0], dp[i][1]) << " ";
    }

    return 0;
}