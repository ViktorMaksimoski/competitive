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
    vector<int> dp(x+1, 1e9);
 
    dp[0] = 0;
    for(int i=0; i<n; i++)
        cin >> coins[i];
 
    for(int i=1; i<=x; i++)
    {
        for(int c : coins)
        {
            if(c > i) continue;
            dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
 
    if(dp[x] == 1e9) cout << -1;
    else cout << dp[x];
    return 0;
}