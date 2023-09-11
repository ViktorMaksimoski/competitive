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

ll dp[51][51][11];
int b;

ll f(int x, int y, int n) {
    //cout << "(" << x1 << ", " << y1 << ") (" << x2 << ", " << y2 << ") " << n << '\n';
    if(x * y < n * b) return 0;
    if(n == 1) return 1;
    if(dp[x][y][n] != -1) return dp[x][y][n];

    ll ans = 0;

    for(int i=1; i<x; i++) {
        if(i * y >= b) {
            ans += f(x-i, y, n-1);
            ans %= mod;
        }

        if((x - i) * y >= b) {
            ans += f(i, y, n-1);
            ans %= mod;
        }
    }

    for(int i=1; i<y; i++) {
        if(x * i >= b) {
            ans += f(x, y-i, n-1);
            ans %= mod;
        }

        if(x * (y - i) >= b) {
            ans += f(x, i, n-1);
            ans %= mod;
        }
    }

    return dp[x][y][n] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int r, c, n;
    cin >> r >> c >> b >> n;

    cout << f(r, c, n) << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    //t = 1;
    while(t--)
        solve();

    return 0;
}