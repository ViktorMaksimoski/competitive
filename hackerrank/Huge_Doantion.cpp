#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define pii pair<int, int>
#define pll pair<long long, long long>
#define debug(x) cout << #x << " = " << x << endl
#define pb push_back
#define eb emplace_back
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main() {
    setIO();

    int t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;
        ll ans = -1;

        ll l=1, r=1e6;
        while(l <= r) {
            auto mid = (l + r) / 2;
            if(1ll * mid * (mid+1) * (2*mid+1) <= 6 * n) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

        cout << ans << '\n';
    }

    return 0;
}