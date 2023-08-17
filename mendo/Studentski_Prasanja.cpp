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

    vector<int> t(n), p(n, 0);
    for(int i=0; i<n; i++) cin >> t[i];
    for(int i=1; i<n; i++) cin >> p[i];

    vector<vector<int> > dp(n+1, vector<int>(2, INT_MAX));
    bool used[n+1][2];
    memset(used, 0, sizeof(used));
    dp[0][0] = 0, dp[0][1] = 0;

    for(int i=1; i<=n; i++) {
        dp[i][0] = t[i-1] + min(dp[i-1][0], dp[i-1][1]);
        if(i > 1) dp[i][1] = p[i-1] + min(dp[i-2][0], dp[i-2][1]);
        if(dp[i][1] < dp[i][0]) used[i][1] = true;
    }

    vector<pii> ans;
    for(int i=n; i>=1; i--) {
        if(used[i][1]) {
            ans.pb({ i-1, i });
            i--;
        }
    }

    reverse(all(ans));
    for(pii &x : ans)
        cout << x.first << " " << x.second << '\n';
    return 0;
}