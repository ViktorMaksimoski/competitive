//CREDITS TO MARKO PETROV AND IVAN ZANOV FOR MOD OPTIMIZATION IDEA
#include <iostream>
#include <iomanip>
#include <cstring>
 
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
 
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
 
ll fac[301];
ll inv[301];
 
ll exp(ll a, ll b) {
    if(!a) return 0;
    ll ans = 1;
 
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
 
    return ans;
}
 
void setComb() {
    fac[0] = 1;
    for(int i=1; i<=300; i++)
        fac[i] = (i * fac[i-1]) % mod;
 
    inv[0] = 1;
    for(int i=1; i<=300; i++)
        inv[i] = exp(fac[i], mod-2);
}
 
ll choose(ll n, ll k) {
    if(k > n) return 0;
    return fac[n] * inv[k] % mod * inv[n-k] % mod;
}
 
int n;
ll dp[2][301][301];
 
ll f(int pos, bool happy, int left) {
    if(pos == n+1) return (happy && !left);
    if(dp[happy][pos][left] != -1) return dp[happy][pos][left];
    if(!left) return dp[happy][pos][left] = happy;
    if(happy) return dp[happy][pos][left] = exp(n - pos + 1, left);
 
    ll ans = 0;
    for(int i=0; i<=left; i++) {
        int newLeft = left - i; // kolku ke mi ostanat
        bool newHappy = happy | (i == pos);
        ll d1 = choose(left, i);
        ll d2 = f(pos+1, newHappy, newLeft);
        ans += (d1 * d2);
        if(i % 16 == 0) ans %= mod;
    }
 
    return dp[happy][pos][left] = ans % mod;
}
 
int32_t main() {
    setIO();
    setComb();
 
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << f(1, 0, n) << '\n';
    return 0;
}