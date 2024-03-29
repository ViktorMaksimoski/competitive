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

const int mod = 1000007;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    map<int, int> factors;
    for(int &x : v) cin >> x;

    for(int &x : v) {
        for(int i=2; i*i<=x; i++) {
            if(x % i > 0) continue;
            int cnt = 0;
            while(x % i == 0) {
                cnt++;
                x /= i;
            }
            factors[i] += cnt;
        }

        if(x > 1) factors[x]++;
    }

    ll ans = 1;

    for(auto &x : factors) {
        if(x.second % 2 == 1) ans *= x.first;
        ans %= mod;
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