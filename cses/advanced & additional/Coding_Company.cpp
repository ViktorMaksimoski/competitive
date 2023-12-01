#include <bits/stdc++.h>
 
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define int long long
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const int K = 5000;
const double eps = 1e-9;
 
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
 
int32_t main() {
    setIO();
 
    int n, x;
    cin >> n >> x;
 
    vector<int> v(n);
    for(int &x : v) cin >> x;
    sort(all(v));
 
    vector<vector<vector<ll> > > dp(2, vector<vector<ll>>(n+1, vector<ll>(x+5001, 0)));
    dp[0][0][K] = 1;
 
    for(int i=0; i<n; i++) {
		for(int j=0; j<=n-i; j++) { 
			for(int k=0; k<=x+K; k++) {
				if(!dp[0][j][k]) continue;
				dp[1][j][k] += dp[0][j][k];
				if(j && k + v[i] <= x + K) dp[1][j-1][k+v[i]] += j * dp[0][j][k];
				if(j + 1 <= n - i - 1) dp[1][j+1][k-v[i]] = dp[0][j][k]; 
				if(j <= n - i - 1) dp[1][j][k] += j * dp[0][j][k];
			}
		}
		for(int j=0; j<=n-i-1; j++) {
			for(int k=0; k<=x+K; k++) {
				dp[0][j][k] = dp[1][j][k] % mod;
				dp[1][j][k] = 0;
			}
		}
	}
 
 
    int ans = 0;
	for(int i=K; i<=x+K; i++) {
		ans += dp[0][0][i];
		ans %= mod;
	}
    cout << ans << '\n';
    return 0;
}