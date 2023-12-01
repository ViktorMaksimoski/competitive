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

ll f(ll a, ll b) {
    if(a == b) return 0;
    
    if(a < b) return min(b-a, 1 + (b % 2 == 1) + f(a, b/2));
    return 1 + (a % 2 == 1) + f((a + 1) / 2, b);
}

int32_t main() {
    setIO();

    int t;
    cin >> t;

    while(t--) {
        ll a, b;
        cin >> a >> b;

        cout << f(a, b) << '\n';
    }

    return 0;
}