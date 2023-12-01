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

    ll n, m, k;
    cin >> n >> m >> k;

    ll l=1, r=n*m;
    ll ans = 0;

    while(l <= r) {
        ll mid = l + (r - l) / 2;
        ll total = 0;

        for(int i=1; i<=n; i++)
            total += min(m, mid / i);

        //cout << mid << ": " << total << '\n';

        if(total >= k) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}