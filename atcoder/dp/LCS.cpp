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

    str a, b;
    cin >> a >> b;
    int n = sz(a), m = sz(b);

    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i == 0 || j == 0) continue;
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    str ans = "";
    while(n && m) {
        if(a[n-1] == b[m-1]) {
            ans += a[n-1];
            n--, m--;
        } else if(dp[n-1][m] > dp[n][m-1]) n--;
        else m--;
    }

    reverse(all(ans));
    cout << ans << '\n';
    return 0;
}