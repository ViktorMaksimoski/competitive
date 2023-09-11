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

    int n, q, s, t;
    ll ans = 0;
    cin >> n >> q >> s >> t;

    vector<int> v(n+1);
    vector<int> diff(n+1);

    for(int i=0; i<=n; i++) {
        cin >> v[i];

        if(i > 0) {
            diff[i] = v[i] - v[i-1];
            if(diff[i] > 0) ans -= (diff[i] * s);
            else ans += (abs(diff[i]) * t);
        }
    }

    while(q--) {
        int l, r, x;
        cin >> l >> r >> x;

        if(diff[l] > 0) ans += (diff[l] * s);
        else ans -= (abs(diff[l]) * t);
        diff[l] += x;
        if(diff[l] > 0) ans -= (diff[l] * s);
        else ans += (abs(diff[l]) * t);

        if(r != n) {
            if(diff[r+1] > 0) ans += (diff[r+1] * s);
            else ans -= (abs(diff[r+1]) * t);
            diff[r+1] -= x;
            if(diff[r+1] > 0) ans -= (diff[r+1] * s);
            else ans += (abs(diff[r+1]) * t);
        }

        cout << ans << '\n';
    }

    return 0;
}