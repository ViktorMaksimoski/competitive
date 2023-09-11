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
const int maxn = 1e6 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

ll fac[2*maxn+1];
ll inv[2*maxn+1];

ll exp(ll a, ll b, ll m) {
    ll ans = 1;

    while(b) {
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b /= 2;
    }

    return ans;
}

ll choose(ll n, ll k) {
    if(k > n) return 0;
    return (fac[n] * inv[k] % mod * inv[n-k] % mod) % mod;
} 

void precomp() {
    fac[0] = 1;
    for(int i=1; i<2*maxn; i++)
        fac[i] = (fac[i-1] * i) % mod;
    inv[0] = 1;
    for(int i=1; i<2*maxn; i++)
        inv[i] = exp(fac[i], mod-2, mod) % mod;
}

int32_t main() {
    setIO();
    precomp();

    int n;
    cin >> n;
    ll ans = 0;

    //levels 0-n form binary tree
    ll curr = 0;
    for(int i=0; i<=n; i++) {
        ans += exp(2, i, mod);
        ans %= mod;
        curr = exp(2, i, mod);
    }

    for(int i=n+1; i<=2*n; i++) {
        ll x = (2 * curr) % mod;
        ll y = (2 * choose(i-1, n)) % mod;
        //cout << i << ": " << x << ", " << y << '\n';
        ll res = x - y;
        res %= mod;
        ans += res;
        ans %= mod;
        curr = res;
    }
    
    cout << (ans + mod) % mod << '\n';
    return 0;
}