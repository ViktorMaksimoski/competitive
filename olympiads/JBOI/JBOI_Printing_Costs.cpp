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

    int n, k, p;
    cin >> n >> k >> p;

    vector<ll> cost(n, 0);
    vector<int> lines(n, 0);

    for(int i=0; i<n; i++) {
        int cnt;
        cin >> cnt;
        vector<pll> dp(cnt+1, {1e18, 1e9});
        vector<int> words(cnt+1, 0);
        dp[0] = {0, 0};

        for(int j=1; j<=cnt; j++) cin >> words[j];

        bool vis[cnt+1][cnt+1];
        ll price[cnt+1][cnt+1];
        memset(vis, 0, sizeof(vis));
        memset(price, 0, sizeof(price));

        for(int j=1; j<=cnt; j++) {
            int curr = 0;
            for(int k=j; k<=cnt; k++) {
                if(k == j) curr += words[j];
                else curr += (words[k] + 1);

                if(curr <= p) {
                    vis[j][k] = 1;
                    price[j][k] = (p - curr) * (p - curr);
                } else break;
            }
        }

        for(int j=1; j<=cnt; j++) {
            for(int k=j; k>=1; k--) {
                if(!vis[k][j]) continue;

                if(j < cnt) {
                    if(dp[j].first == dp[k-1].first + price[k][j]) {
                        dp[j].second = min(dp[j].second, dp[k-1].second + 1);
                    } else if(dp[j].first > dp[k-1].first + price[k][j]) {
                        dp[j].first = dp[k-1].first + price[k][j];
                        dp[j].second = dp[k-1].second + 1;
                    }
                } else {
                    if(dp[j].first == dp[k-1].first) {
                        dp[j].second = min(dp[j].second, dp[k-1].second + 1);
                    } else if(dp[j].first > dp[k-1].first) {
                        dp[j].first = dp[k-1].first;
                        dp[j].second = dp[k-1].second + 1;
                    }
                }
            }
        }

        cost[i] = dp[cnt].first;
        lines[i] = dp[cnt].second;
    }

    ll ans = 0;
    int currLine = 0;

    for(int i=0; i<n; i++) {
        ans += cost[i];
        if(currLine == 0) {
            currLine = lines[i];
        } else {
            if(currLine + 1 + lines[i] <= k) {
                currLine += (1 + lines[i]);
            } else {
                ans += (k - currLine);
                currLine = lines[i];
            }
        }
    }

    cout << ans + (k - currLine) << '\n';
    return 0;
}