#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Cow { int h, w, s; };
struct Data { int diff, total; };

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, h, ans = -1;
    cin >> n >> h;

    vector<Cow> cows(n);
    for(Cow &c : cows) cin >> c.h >> c.w >> c.s;

    vector<Data> dp(1 << n);
    dp[0].total = 0, dp[0].diff = INT_MAX;

    for(int s=1; s<(1<<n); s++) {
        dp[s].total = 0, dp[s].diff = -1;
        for(int j=0; j<n; j++) {
            if(s & (1 << j)) {
                dp[s].total += cows[j].h;
                dp[s].diff = max(dp[s].diff, min(
                    dp[s^(1<<j)].diff - cows[j].w,
                    cows[j].s
                ));
            }
        }

        if(dp[s].total >= h)
            ans = max(ans, dp[s].diff);
    }

    if(ans >= 0) cout << ans << '\n';
    else cout << "Mark is too tall\n";
    return 0;
}