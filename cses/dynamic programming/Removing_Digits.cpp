	0.03 s	details
#12	ACCEPTED	0.03 s	details
#13	ACCEPTED	0.00 s	details
Code
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
    vector<int> dp(n + 1, 1e9);
 
    dp[0] = 0;
 
    for(int i=1; i<=n; i++)
        for(char ch : to_string(i))
            dp[i] = min(dp[i], dp[i - (ch - '0')] + 1);
 
    cout << dp[n] << "\n";
    return 0;
}