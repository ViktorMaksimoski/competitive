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
const int maxn = 1e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

ll exp(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

ll fac[102], inv[102];

void precomp() {
    fac[0] = 1, inv[0] = 1;
    for(int i=1; i<102; i++) {
        fac[i] = (fac[i-1] * i) % mod;
        inv[i] = exp(fac[i], mod-2);
    }
}

inline ll choose(ll n, ll k) {
    return fac[n] * inv[k] % mod * inv[n-k] % mod;
}

vector<int> v;
int n, m;

void solve() {
    cin >> n >> m;

    v.clear();
    v.resize(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];

    vector<vector<ll> > dp(n+1, vector<ll>(n+1, 0));
    dp[0][0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            dp[i][j] = dp[i-1][j];
            int cnt = 0;
            for(int k=i; k>=1; k--) {
                cnt += (v[k] == v[i]);
                if(cnt >= m && v[k] == v[i]) {
                    dp[i][j] += dp[k-1][j-1] * choose(cnt-2, m-2);
                    dp[i][j] %= mod;
                }
            }
        }
    }
    
    for(int i=n; i>=0; i--) {
        if(dp[n][i] > 0) {
            cout << dp[n][i] << '\n';
            return ;
        }
    }
}

int32_t main() {
    setIO();
    precomp();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}