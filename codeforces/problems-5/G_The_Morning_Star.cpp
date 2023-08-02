#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair

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
    cin >> n;
    ll ans = 0;
    unordered_map<ll, ll> a, b, c, d;
    for(int i=0; i<n; i++) {
        ll x, y;
        cin >> x >> y;
        a[x]++;
        b[y]++;
        c[x-y]++;
        d[x+y]++;
    }

    for(auto &x : a) ans += (1ll * x.second * (x.second-1));
    for(auto &x : b) ans += (1ll * x.second * (x.second-1));
    for(auto &x : c) ans += (1ll * x.second * (x.second-1));
    for(auto &x : d) ans += (1ll * x.second * (x.second-1));
        
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