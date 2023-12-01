#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair
#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
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

void solve() {
    int n;
    ll k, total = 0;
    cin >> n >> k;
    vector<int> v(n);
    for(int &x : v) cin >> x, total += x;
    sort(all(v));

    if(total <= k) {
        cout << 0 << '\n';
        return;
    }

    if(n == 1) {
        cout << v[0] - k << '\n';
        return ;
    }

    ll ans = total - k;
    ll sum = v[0];

    ll tmp1 = 0, tmp2 = 0;
    for(int i=n-1; i>0; i--) {
        if(total - tmp2 <= k) {
            ans = min(ans, tmp1);
        }

        tmp1++;
        tmp2 += (v[i] - v[0]);
    }

    for(int i=n-1; i>=1; i--) {
        sum += v[i];
        ll total2 = total - sum;
        
        ll lp=0, rp=1e12;
        // res treba da bide nekoj golem broj
        //originalno imav: ll res = 0;
        ll res = 1e15;
        while(lp <= rp) {
            auto mid = lp + (rp - lp) / 2;
            ll curr = total2 + 1ll * (n - i + 1) * (v[0] - mid);
            if(curr <= k) {
                res = mid;
                rp = mid - 1;
            } else lp = mid + 1;
        }
        
        ans = min(ans, 1ll * (n - i) + res);
    }

    cout << ans << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}