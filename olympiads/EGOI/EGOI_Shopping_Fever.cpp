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

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int &x : v) cin >> x;
    sort(rall(v));

    vector<ll> dp(n, 0);
    dp[0] = (v[0] * (100 - q)) / 100;
    if(n >= 2) dp[1] = dp[0] + (v[1] * (100 - q)) / 100;

    for(int i=2; i<n; i++) {
        //get only this one
        dp[i] = dp[i-1] + (v[i] * (100 - q)) / 100;

        //get this one with the previous 2
        if(i == 2) dp[i] = min(dp[i], (v[0] + v[1]) * 1ll);
        else dp[i] = min(dp[i], (v[i-1] + v[i-2] * 1ll) + dp[i-3]);
    }

    cout << dp[n-1] << '\n';
    return 0;
}