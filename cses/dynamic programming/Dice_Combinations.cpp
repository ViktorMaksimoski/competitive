#include <bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
#define ull unsigned long long
using namespace std;
 
int main()
{
    int n;
    ll mod = 1e9 + 7;
    cin >> n;
 
    ll dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    if(n > 1) dp[2] = 2;
 
    if(n > 2)
    {
        for(int i=3; i<=n; i++)
        {
            dp[i] = 0;
            int to;
            if(i >= 7) to = 6;
            else if(i == 3) to = 2;
            else if(i == 4) to = 3;
            else if(i == 5) to = 4;
            else if(i == 6) to = 5;
            for(int j=1; j<=to; j++)
            {
                dp[i] += dp[i-j];
                dp[i] %= mod;
            }
            if(i <= 6) dp[i]++;
        }
    }
 
    cout << dp[n] << endl;
 
    return 0;
}