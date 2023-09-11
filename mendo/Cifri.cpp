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

    string n;
    int k;
    cin >> n >> k;

    ll ans = 0;

    for(int s=0; s<(1<<sz(n)); s++) {
        if(__builtin_popcount(s) != sz(n) - k) continue;
        ll ans2 = 0;

        for(int i=0; i<sz(n); i++) {
            if(s & (1 << i)) {
                ans2 *= 10;
                ans2 += (n[i] - '0');
            }
        }

        ans = max(ans, ans2);
    }

    cout << ans << '\n';
    return 0;
}