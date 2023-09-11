#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
int mat[52][52];
ll prefix[52][52];

//dp[x1][y1][x2][y2] - min cena da se podeli pravoagolnik (x1, y1), (x2, y2)
//na 1x1 kvadratcinja
ll dp[52][52][52][52];

ll query(int x1, int y1, int x2, int y2) {
    ll ans = 0;

    ans += prefix[x2][y2];
    ans -= prefix[x1-1][y2];
    ans -= prefix[x2][y1-1];
    ans += prefix[x1-1][y1-1];

    return ans;
}

ll f(int x1, int y1, int x2, int y2) {
    if(x1 > n || x2 > n || y1 > m || y2 > m) return 0;
    if(x1 < 1 || x2 < 1 || y1 < 1 || y2 < 1) return 0;
    if(x1 == x2 && y1 == y2) return 0;
    if(dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];

    ll ans = 1e16;

    for(int i=x1; i<x2; i++)
        ans = min(ans, f(x1, y1, i, y2) + f(i+1, y1, x2, y2));
    for(int i=y1; i<y2; i++)
        ans = min(ans, f(x1, y1, x2, i) + f(x1, i+1, x2, y2));

    return dp[x1][y1][x2][y2] = ans + query(x1, y1, x2, y2);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    memset(prefix, 0, sizeof(prefix));
    memset(dp, -1, sizeof(dp));

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> mat[i][j];

    //build prefix table
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            prefix[i][j] += mat[i][j];
            prefix[i][j] += prefix[i-1][j];
            prefix[i][j] += prefix[i][j-1];
            prefix[i][j] -= prefix[i-1][j-1];
        }
    }

    cout << f(1, 1, n, m) << '\n';
    return 0;
}