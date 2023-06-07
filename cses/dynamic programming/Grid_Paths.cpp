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
 
    int n;
    cin >> n;
 
    int grid[n][n];
 
    for(int i=0; i<n; i++)
    {
        string s;
        cin >> s;
        for(int j=0; j<n; j++)
        {
           grid[i][j] = s[j];
        }
    }
 
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(grid[i][j] == '*') dp[i][j] = 0;
            else
            {
                if(i > 0) dp[i][j] += dp[i-1][j];
                if(j > 0) dp[i][j] += dp[i][j-1];
                dp[i][j] %= 1000000007;
            }
        }
    }
 
    cout << dp[n-1][n-1];
    return 0;
}