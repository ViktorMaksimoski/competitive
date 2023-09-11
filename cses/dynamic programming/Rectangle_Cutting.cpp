#include <bits/stdc++.h>
using namespace std;
 
int n, m;
int dp[501][501];
 
int f(int a, int b) {
    if(a == b) return 0;
    if(dp[a][b] != -1) return dp[a][b];
    int ans = 1e9;
 
    for(int i=1; i<a; i++)
        ans = min(ans, 1 + f(i, b) + f(a - i, b));
    for(int i=1; i<b; i++)
        ans = min(ans, 1 + f(a, i) + f(a, b - i));
 
    return dp[a][b] = ans;
}
 
int32_t main() {
    memset(dp, -1, sizeof(dp));
 
    cin >> n >> m;
    cout << f(n, m) << '\n';
    return 0;
}