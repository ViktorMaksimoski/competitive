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

    int k, l, m;
    cin >> k >> l >> m;

    int mx = 0;
    vector<int> v(m);
    for(int &x : v) cin >> x, mx = max(mx, x);

    vector<bool> dp(mx+1, 0);
    dp[0] = 0;
    
    for(int i=1; i<=mx; i++) {
        int d1 = dp[i-1];
        int d2 = (i >= k ? dp[i-k] : 1);
        int d3 = (i >= l ? dp[i-l] : 1);
        dp[i] = !(d1 & d2 & d3);
    }

    for(int &x : v) cout << (dp[x] ? 'A' : 'B');
    return 0;
}