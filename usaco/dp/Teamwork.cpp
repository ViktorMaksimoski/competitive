#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    setUSA("teamwork");

    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    vector<ll> dp(n, 0);
    vector<vector<int> > table(n, vector<int>(20, 0));
    vector<int> bin_log(n+1, 0);
    for(int i=0; i<n; i++) cin >> v[i], table[i][0] = v[i];

    for(int k=1; k<20; k++)
        for(int i=0; i+(1<<k)-1<n; i++)
            table[i][k] = max(table[i][k-1], table[i+(1<<(k-1))][k-1]);

    bin_log[1] = 0;
    for(int i=2; i<=n; i++) bin_log[i] = 1 + bin_log[i/2];

    auto query = [&](int a, int b) {
        int len = b - a + 1;
        int k = bin_log[len];
        return max(
            table[a][k],
            table[b-(1<<k)+1][k]
        );
    };

    dp[0] = v[0];
    for(int i=1; i<n; i++) {
        dp[i] = v[i] + dp[i-1];
        for(int j=max(0, i-k+1); j<i; j++) {
            if(j == 0) {
                dp[i] = max(dp[i], 1ll * query(0, i) * (i - j + 1));
            } else {
                dp[i] = max(dp[i], dp[j-1] + 1ll * query(j, i) * (i - j + 1));
            }
        }
    }

    cout << dp[n-1] << '\n';
    return 0;
}