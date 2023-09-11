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

int32_t main() {
    setIO();

    int n, m;
    ll mx = 0;
    cin >> n >> m;
    ll total = n-1;

    vector<ll> v(n);
    for(ll &x : v) {
        cin >> x;
        mx = max(mx, x);
        total += x;
    }

    ll ans = 1e18;
    ll l = mx, r = total;
    //cout << l << " " << r << '\n';
    while(l <= r) {
        ll mid = l + (r - l) / 2;

        int lines = 1;
        ll curr = 0;
        int cnt = 0;

        for(ll x : v) {
            cnt++;
            if(cnt >= 2) curr++;
            curr += x;

            if(curr > mid) {
                curr = x;
                cnt = 1;
                lines++;
            }
        }

        if(lines <= m) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}