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

const int mod = 998244353;
const int LOG = 20;
const int maxn = 1e6 + 5;
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

inline ll inv(ll a) {
    return exp(a, mod-2);
}

int32_t main() {
    setIO();

    int n;
    cin >> n;

    vector<vector<int> > v(n+1);
    vector<int> cnt(maxn+1, 0);
    //cout << exp(2, 10) << '\n';

    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        for(int j=0; j<a; j++) {
            int b;
            cin >> b;
            v[i].push_back(b);
            cnt[b]++;
        }
    }

    ll ans = 0;

    for(int i=1; i<=n; i++) {
        for(int &x : v[i]) {
            ll a = cnt[x] % mod;
            ll b = exp(n, 2) * sz(v[i]) % mod;
            ans += (a * inv(b)) % mod;
            ans %= mod;
        }
    }

    cout << ans % mod << '\n';
    return 0;
}