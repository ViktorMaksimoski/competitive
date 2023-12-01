#include <bits/stdc++.h>
#define ii pair<int, int>
#define il pair<int, long long>
#define ll long long
#define i3 pair<int, pair<int, int> >
#define ull unsigned long long
#define pb push_back
#define inf INT_MAX
#define f first
#define s second
#define ms(a, y) memset(a, y, sizeof(a))
using namespace std;
 
void setIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
int main()
{
    //setIO();
 
    int n;
    string s;
    cin >> n >> s;
    s = "?" + s;
 
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
 
    for(int len=2; len<=n; len++)
    {
        for(int i=1; i<=n-len; i++)
        {
            int j = i + len;
 
            bool connect = (s[i] == 'A' && s[j] == 'U') || (s[i] == 'U' && s[j] == 'A')
                    || (s[i] == 'C' && s[j] == 'G') || (s[i] == 'G' && s[j] == 'C')
                    || (s[i] == 'G' && s[j] == 'U') || (s[i] == 'U' && s[j] == 'G');
 
            if(connect)
                dp[i][j] = dp[i+1][j-1] + 1;
 
            for(int k=i+1; k<=j; k++)
                dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k][j]);
        }
    }
 
    cout << dp[1][n] << '\n';
    return 0;
}