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

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    ll ans = 0;
    int l=0, r=n-1;
    sort(all(v));

    while(l <= r) {
        ll sum = 0;
        bool ok = 0;
        //cout << l << " " << r << '\n';
        for(int i=l; i<r; i++) {
            ll temp = sum;
            sum += min(v[i], v[r] - sum);
            v[i] -= min(v[i], v[r] - temp);
            if(sum == v[r]) {
                l = i + (v[i] == 0);
                r--;
                ans += (sum + 1);
                ok = 1;
                break;
            }

        }

        if(!ok && v[r] + sum > 0) {
            ll total = v[r] + sum;
            while(total > 1) {
                ans += (1 + (total % 2 == 1));
                total /= 2;
            }
            if(total == 1) ans++;
            break;
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}