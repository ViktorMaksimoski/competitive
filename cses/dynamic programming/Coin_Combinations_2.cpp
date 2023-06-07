#include <bits/stdc++.h>
#define ii pair<int, int>
#define il pair<int, long long>
#define ll long long
#define ull unsigned long long
#define pb push_back
using namespace std;
 
void setIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
 
int main()
{
    setIO();
 
    int n, x;
    cin >> n >> x;
 
    vector<int> coins(n);
    vector<vector<int> > dp(n+1, vector<int>(x+1, 0));
 
    dp[0][0] = 1;
    for(int i=0; i<n; i++)
        cin >> coins[i];
 
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=x; j++)
        {
            dp[i][j] = dp[i-1][j];
            int left = j - coins[i-1];
            if(left >= 0)
                dp[i][j] += dp[i][left];
 
            dp[i][j] %= 1000000007;
        }
    }
 
    cout << dp[n][x] << "\n";
 
    return 0;
}