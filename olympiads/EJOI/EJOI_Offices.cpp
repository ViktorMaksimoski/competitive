#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
//#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e3 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

ll fac[maxn+1];
ll inv[maxn+1];
 
ll exp(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}
 
ll choose(ll n, ll k) {
    if(n < k) return 0;
    return fac[n] * inv[k] % mod * inv[n-k] % mod; 
}
 
void setComb() {
    fac[0] = 1;
    for(int i=1; i<=maxn; i++)
        fac[i] = (i * fac[i-1]) % mod;
 
    inv[maxn] = exp(fac[maxn], mod-2);
    for(int i=maxn; i>0; i--)
        inv[i-1] = (inv[i] * i) % mod;
}

int32_t main() {
    setIO();
    setComb();

    int n, m, t;
    cin >> n >> m >> t;

    char mat[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> mat[i][j];

    if(n == 1) {
        ll ans = 0;

        if(t == 1) ans = exp(2, m) - 1 - m;
        else if(t == 2) ans = choose(m, 2);
        else ans = choose(m, 3);

        cout << ans << '\n';
        return 0;
    }

    if(n <= 2 && m <= 2){
        ll ans = 0;

        return ans;
    }

    if(t == 2) {
        
    }

    return 0;
}