#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<ll> > dp(n, vector<ll>(8, 0));
    dp[0][(s[0] - '0') % 8] = 1;

    for(int i=1; i<n; i++) {
        for(int j=0; j<8; j++) {
            dp[i][j] = dp[i-1][j];
        }

        dp[i][(s[i] - '0') % 8]++;
        dp[i][(s[i] - '0') % 8] %= mod;

        for(int j=0; j<8; j++) {
            int newMod = 10 * j + (s[i] - '0');
            newMod %= 8;
            dp[i][newMod] += dp[i-1][j];
            dp[i][newMod] %= mod;
        }
    }

    cout << dp[n-1][0] % mod << '\n';
    return 0;
}