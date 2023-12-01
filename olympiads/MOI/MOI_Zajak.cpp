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
    int mat[n][m];
 
    for(int i=0; i<n; i++)  
        for(int j=0; j<m; j++)
            cin >> mat[i][j];
 
    int dp[n][m];
    memset(dp, 0, sizeof(dp));
 
    dp[0][0] = mat[0][0];
    for(int j=1; j<m; j++)
        dp[1][j] = dp[0][0] + mat[1][j] + mat[0][j];
 
    for(int i=2; i<n; i++) {
        for(int j=0; j<m; j++) {
            dp[i][j] = mat[i][j];
            for(int k=0; k<j; k++)
                dp[i][j] = max(dp[i][j], mat[i][j] + mat[i-1][j] + dp[i-1][k]);
            for(int k=j+1; k<m; k++)
                dp[i][j] = max(dp[i][j], mat[i][j] + mat[i-1][j] + dp[i-1][k]);
        }
    }
 
    for(int j=0; j<m-1; j++)
        dp[n-1][m-1] = max(dp[n-1][m-1], dp[n-1][j] + mat[n-1][m-1]);
 
    cout << dp[n-1][m-1];
    return 0;
}