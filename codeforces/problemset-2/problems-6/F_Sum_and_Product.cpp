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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

ll bin_sqrt(ll x) {
    ll ans = 0;

    ll lp=0, rp=3e9+1;
    while(lp <= rp) {
        auto mid = lp + (rp - lp) / 2;
        if(1ll * mid * mid <= x) {
            ans = mid;
            lp = mid + 1;
        } else {
            rp = mid - 1;
        }
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;
    map<int, int> occ;
    
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        occ[x]++;
    }

    int q;
    cin >> q;
    while(q--) {
        ll b, c;
        cin >> b >> c;

       ll D = 1ll * b * b - 4ll * c;

       if(D < 0) {
            cout << 0 << " ";
            continue;
       }

       ll x1 = (b - bin_sqrt(D)) / 2ll;
       ll x2 = (b + bin_sqrt(D)) / 2ll;

       if(x1 + x2 != b) {
            cout << 0 << " ";
            continue;
        }
 
        if(1ll * x1 * x2 != c) {
            cout << 0 << " ";
            continue;
        }
 
        ll ans = 0;
 
        if(x1 == x2) {
            ans = 1ll * (occ[x1] * (occ[x1] - 1)) / 2;
        } else {
            ans = 1ll * occ[x1] * occ[x2];
        }
 
        cout << ans << " ";
    }

    cout << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}