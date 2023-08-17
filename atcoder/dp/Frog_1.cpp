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

    int n;
    cin >> n;

    vector<int> v(n);
    for(int &x : v) cin >> x;
    vector<ll> dp(n, 1e18);
    dp[0] = 0;
    dp[1] = abs(v[1] - v[0]);

    for(int i=2; i<n; i++)
        dp[i] = min({ dp[i], abs(v[i] - v[i-1]) + dp[i-1], abs(v[i] - v[i-2]) + dp[i-2] });

    cout << dp[n-1] << '\n';
    return 0;
}