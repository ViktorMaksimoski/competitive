#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
//#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;
    int a[n][m], b[n][m];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> a[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> b[i][j];

    int cost[n][m], mask[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int mx = 0;
            cost[i][j] = mask[i][j] = 0;
            for(int k=0; k<n; k++) {
                if(a[i][j] == a[k][j]) {
                    mask[i][j] |= (1 << k);
                    cost[i][j] += b[k][j];
                    mx = max(mx, b[k][j]);
                }
            }
            cost[i][j] -= mx;
        }
    }

    vector<int> dp(1<<n, 1e9);
    dp[0] = 0;

    for(int s=1; s<(1<<n); s++) {
        for(int i=0; i<n; i++) {
            if(s & (1 << i)) {
                for(int j=0; j<m; j++) {
                    dp[s] = min(dp[s], dp[s^mask[i][j]] + cost[i][j]);
                    dp[s] = min(dp[s], dp[s^(1<<i)] + b[i][j]);
                }
            }
        }
    }

    cout << dp[(1<<n)-1] << '\n';
    return 0;
}