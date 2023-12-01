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

const int mod = 750083;
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

    string a, b;
    cin >> a >> b;
   
    int n = sz(a), m = sz(b);
    int dp_min[n+1][m+1], dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    dp_min[0][0] = 0;

    for(int i=0; i<=n; i++) { 
        for (int j=0; j<=m; j++) {  
            if(!i) dp_min[i][j] = j; 
            else if(!j) dp_min[i][j] = i; 
            else if (a[i-1] == b[j-1]) dp_min[i][j] = 1 + dp_min[i-1][j-1]; 
            else dp_min[i][j] = 1 + min(dp_min[i-1][j], dp_min[i][j-1]); 
        } 
    }

    dp[0][0] = 1;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {

            if(i && j && a[i-1] == b[j-1] && dp_min[i-1][j-1] + 1 == dp_min[i][j]) {
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= mod;
            } else {
                if(i && dp_min[i-1][j] + 1 == dp_min[i][j]) {
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] %= mod;
                }

                if(j && dp_min[i][j-1] + 1 == dp_min[i][j]) {
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] %= mod;
                }
            }
        }
    }

    //cout << dp_min[n][m] << '\n';
    cout << dp[n][m] << '\n';
    return 0;
}