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
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    while(q--) {
        ll k, ans = 0;
        cin >> k;

        vector<ll> v2(n);
        for(int i=0; i<n; i++) v2[i] = v[i];

        for(int b=62; b>=0; b--) {
            ll total = 0;
            for(int i=0; i<n; i++) {
                if(v2[i] & (1ll << b)) continue;
                ll need = (1ll << b) - (v2[i] % (1ll << b));
                total += need;
                if(total > 1e18) break;
            }

            if(k >= total) {
                ans |= (1ll << b);
                k -= total;
                for(int i=0; i<n; i++) {
                    if(v2[i] & (1ll << b)) continue;
                    v2[i] += ((1ll << b) - (v2[i] % (1ll << b)));
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}