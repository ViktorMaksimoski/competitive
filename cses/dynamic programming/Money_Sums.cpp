#include <bits/stdc++.h>
#define ii pair<int, int>
#define il pair<int, long long>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define f first
#define s second
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
 
    int n, total = 0;
    cin >> n;
 
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
        total += v[i];
    }
 
    //dali moze da se sostavi suma j so i moneti
    bool dp[n+1][total+1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
 
    for(int i=1; i<=n; i++)
    {
        for(int sum=0; sum<=total; sum++)
        {
            dp[i][sum] = dp[i-1][sum];
            int left = sum - v[i-1];
 
            if(left >= 0 && dp[i-1][left])
                dp[i][sum] = true;
        }
    }
 
 
    vector<int> res;
 
    for(int i=1; i<=total; i++)
    {
        if(dp[n][i])
            res.pb(i);
    }
 
    cout << res.size() << '\n';
    for(int x : res)
        cout << x << " ";
 
    return 0;
}