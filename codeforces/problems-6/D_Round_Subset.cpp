#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

int getPow(ll x, ll d) {
    int cnt = 0;

    while(x % d == 0) {
        cnt++;
         x /= d;
    }

    return cnt;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    ll mx = 0;
    cin >> n >> m;

    vector<ll> v(n);
    vector<int> pow2(n), pow5(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
        pow2[i] = getPow(v[i], 2);
        pow5[i] = getPow(v[i], 5);
    }

    ll ans = 0; 
    ll maxC = 6001;
    vector<vector<vector<ll> > > dp(2, vector<vector<ll> >(m+1, vector<ll>(6001, -1)));
    dp[0][0][0] = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<=m; j++) {
            for(int k=0; k<maxC; k++) {
                if(k >= pow5[i] && j > 0 && dp[0][j-1][k-pow5[i]] != -1) 
                    dp[1][j][k] = max(dp[1][j][k], dp[0][j-1][k-pow5[i]] + pow2[i]);
                if(dp[0][j][k] != -1)
                    dp[1][j][k] = max(dp[1][j][k], dp[0][j][k]);
            }
        }

        swap(dp[0], dp[1]);
    }

    for(int i=0; i<maxC; i++)
        ans = max(ans, min(i, dp[0][m][i]));
    cout << ans << '\n';
    return 0;
}