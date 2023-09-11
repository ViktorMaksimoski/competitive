#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int bits(int x) {
    return __builtin_popcount(x);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, ans = 1e9;
    cin >> n;

    //dp[i][j] - kolku najmalku swaps ako gi gledame prvite i brojki
    // i posledniot e ednakov na j;
    vector<vector<int> > dp(n+1, vector<int>(4096, 1e9));
    dp[0][0] = 0;

    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;

        int curr = 1;
        int mn = dp[i-1][0];

        for(int j=1; j<(1<<12); j++) {
            if(bits(j) != bits(x)) continue;
            int common = bits(j) - bits(j & x);

            for(int k=curr; k<=j; k++)
                if(dp[i-1][k] < mn)
                    mn = dp[i-1][k];

            dp[i][j] = min(dp[i][j-1], mn + common);
            if(i == n) ans = min(ans, dp[i][j]);
            curr = j;
        }
    }

    cout << ans << '\n';
    return 0;
}