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

    ll r, c, n;
    cin >> r >> c >> n;
    if(r > c) swap(r, c);

    ll total = r * c;

    if(n > total) {
        cout << -1 << '\n';
        return 0;
    }

    if(n == total) {
        cout << 0 << '\n';
        return 0;
    }

    int ans = 5;

    for(int i=1; i*i<=n; i++) {
        if(n % i > 0) continue;
        int a = i;
        int b = n / i;

        //cout << a << " " << b << '\n';

        if(a < r && b < c) {
            ans = min(ans, 2);
        } 
        if(a < r && b == c) {
            ans = min(ans, 1);
        }
        if(a == r && b < c) {
            ans = min(ans, 1);
        }
        if(a == c && b < r) {
            ans = min(ans, 1);
        }
        if(b == r && a < c) {
            ans = min(ans, 1);
        }
    }

    cout << (ans == 5 ? -1 : ans) << '\n';
    return 0;
}