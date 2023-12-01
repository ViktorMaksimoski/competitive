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

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    int need_x = n / x;
    int need_y = n / y;
    int z = lcm(x, y);
    need_x -= (n / z);
    need_y -= (n / z);

    ll ans_x = 1ll * n * (n + 1);
    ll ans_y = 1ll * need_y * (need_y + 1);
    ans_y /= 2; ans_x /= 2;

    ll ans = 1ll * (n - need_x) * (n - need_x + 1);
    ans /= 2;
    ans_x -= ans;

    //cout << need_x << " " << need_y << '\n';
    cout << ans_x - ans_y << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}