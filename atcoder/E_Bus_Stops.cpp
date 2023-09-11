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

int lcm(int a, int b) {
    return a * b / __gcd(a, b);
}

int32_t main() {
    setIO();

    int n, x, y;
    int period = 1;
    cin >> n >> x >> y;

    vector<int> p(n-1), t(n-1);
    for(int i=0; i<n-1; i++) cin >> p[i] >> t[i], period = lcm(period, p[i]);

    vector<int> calc(period, 0);

    for(int i=0; i<period; i++) {
        int curr = i;

        for(int j=0; j<n-1; j++) {
            if(curr % p[j] != 0) curr += (p[j] - curr % p[j]);
            curr += t[j];
        }

        calc[i] = curr - i;
    }

    int q;
    cin >> q;
    //q = 1;
    while(q--) {
        int tm;
        cin >> tm;
        int ans = tm + x;

        // for(int32_t i=0; i<n-1; i++) {
        //     if(ans % p[i] != 0) ans += (p[i] - ans % p[i]);
        //     ans += t[i];
        // }

        cout << ans + calc[ans%period] + y << '\n';
    }

    //cout << calc[15] << '\n';
    return 0;
}