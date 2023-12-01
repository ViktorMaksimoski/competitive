#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

ll fac[maxn+1];
ll inv[maxn+1];

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
    if(n < k) return 0;
    return fac[n] * inv[k] % mod * inv[n-k] % mod; 
}

//koga easy verzija e poteska od hard :(
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    sort(all(v));

    ll ans = 0;
    for(int i=0; i<=n-m; i++) {
        int j = i + (m - 1);
        if(v[j] - v[i] > k) continue;
        int last = -1;
        int lp=j, rp=n-1;

        while(lp <= rp) {
            int mid = (lp + rp) / 2;
            if(v[mid] - v[i] > k) {
                rp = mid - 1;
            } else {
                last = mid;
                lp = mid + 1;
            }
        }

        ans += choose(last - i, m - 1);
        ans %= mod;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fac[0] = 1;
    for(int i=1; i<maxn; i++)
        fac[i] = (i * fac[i-1]) % mod;

    inv[0] = 1;
    for(int i=1; i<maxn; i++)
        inv[i] = exp(fac[i], mod-2, mod);

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}