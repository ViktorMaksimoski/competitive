#include <bits/stdc++.h>
using namespace std;
using ll = long long;
   
const int mod = 123456789;
   
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    int n, m=0;
    cin >> n;
    vector<int> v(n+1, 1e9);
    for(int i=1; i<=n; i++) cin >> v[i], m = max(m, v[i]);
   
    vector<vector<int> > dp(2, vector<int>(m+1, 0));
    vector<vector<int> > pref(2, vector<int>(m+1, 0));
    for(int i=0; i<=v[1]; i++) dp[0][i] = 1, pref[0][i] = i + 1;
   
    for(int i=2; i<=n; i++) {
        for(int x=0; x<=v[i]; x++) {
            dp[1][x] = pref[1][x] = 0;
            int y = v[i] - x, k = v[i-1] - y;
            if(k >= x) k = x;
 
            if(k < 0) continue;
            dp[1][x] = pref[0][k];
            pref[1][x] = dp[1][x];
            if(x) pref[1][x] = (pref[1][x] + pref[1][x-1]) % mod;
        }

        swap(dp[0], dp[1]);
        swap(pref[0], pref[1]);
    }
   
    cout << pref[0][v[n]] << '\n';
    return 0;
}