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
const int maxn = 2e5 + 50;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];

    vector<int> dp(n+1);
    vector<int> best(n+1, -1e9);

    for(int i=1; i<=n; i++) {
        dp[i] = max(dp[i-1], i + best[v[i]]);
        best[v[i]] = max(best[v[i]], dp[i-1] - i + 1);
        
    }

    cout << dp[n] << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}