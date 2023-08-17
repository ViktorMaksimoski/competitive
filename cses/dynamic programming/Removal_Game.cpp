#include <bits/stdc++.h>
 
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
 
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
 
int v[5001];
ll dp[5001][5001][2];
int n;
 
ll f(int l, int r, int x) {
    if(dp[l][r][x] > -1e15) return dp[l][r][x];
    if(l == r) return dp[l][r][x] = (x ? 0 : v[l]);
 
    if(!x) {
        ll d1 = v[l] + f(l+1, r, !x);
        ll d2 = v[r] + f(l, r-1, !x);
        return dp[l][r][x] = max(d1, d2);
    } else {
        ll d1 = f(l+1, r, !x);
        ll d2 = f(l, r-1, !x);
        return dp[l][r][x] = min(d1, d2);
    }
}
 
int32_t main() {
    setIO();
 
    cin >> n;
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
                for(int k=0; k<2; k++)
                    dp[i][j][k] = -1e15;
 
    for(int i=0; i<n; i++) cin >> v[i];
 
    cout << f(0, n-1, 0) << '\n';
    return 0;
}