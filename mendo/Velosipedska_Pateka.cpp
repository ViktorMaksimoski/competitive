#include <bits/stdc++.h>
using namespace std;

struct Light { int x, c, r; };

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int len, b, n;
    cin >> len >> b >> n;
    vector<Light> v(n);
    for(Light &l : v) cin >> l.x >> l.c >> l.r;

    vector<vector<int> > dp(n+1, vector<int>(b+1, 0));
    vector<vector<bool> > used(n+1, vector<bool>(b+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=b; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= v[i-1].c) {
                int prev = dp[i-1][j-v[i-1].c];
                int left = v[i-1].x - max(0, v[i-1].x - v[i-1].r);
                int right = min(len, v[i-1].x + v[i-1].r) - v[i-1].x;
                dp[i][j] = max(dp[i][j], prev + left + right);
                used[i][j] = (dp[i][j] > dp[i-1][j]);
            }
        }
    }

    vector<int> hasLight(len, 0);
    int curr = b;
    for(int i=n; i>=1; i--) {
        if(!used[i][curr]) continue;
        int l = max(0, v[i-1].x - v[i-1].r);
        int r = min(len-1, v[i-1].x + v[i-1].r - 1);
        for(int j=l; j<=r; j++) hasLight[j] = true;
        curr -= v[i-1].c;
    }

    int ans = 0, cnt = 0;
    for(int i=0; i<len; i++) {
        if(!hasLight[i]) cnt++, ans = max(ans, cnt);
        else cnt = 0;
    }

    cout << dp[n][b] << " " << ans << '\n';
    return 0;
}