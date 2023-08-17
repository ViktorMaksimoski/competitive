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
    for(int i=1; i<=n; i++)
        v.push_back(i);

    int sum = (n * (n + 1)) / 2;
    
    if(sum & 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<vector<ll> > dp(n+5, vector<ll>(sum/2+5, 0));
    dp[1][0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=sum/2; j++) {
            dp[i][j] += dp[i-1][j];
            if(j >= i) dp[i][j] += dp[i-1][j-i];
            dp[i][j] %= mod;
        }
    }

    cout << dp[n][sum/2] << '\n';
    return 0;
}