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

int bits(int x) {
    return __builtin_popcount(x);
}

int n, l;
ll t;
vector<ll> v;
ll dp[101][101][10001];

int32_t main() {
    memset(dp, 0, sizeof(dp));
    setIO();

    cin >> n >> l >> t;
    v.resize(n);

    for(ll &x : v) cin >> x;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=l; j++) {
            for(int k=0; k<10001; k++) {
                dp[i][j][k] = dp[i-1][j][k];

                if(j > 0 && k >= (i - j))
                    dp[i][j][k] = max(dp[i][j][k], v[i-1] + dp[i-1][j-1][k-(i-j)]);
            }
        }
    }

    for(int i=0; i<10001; i++) {
        if(dp[n][l][i] >= t) {
            cout << i << '\n';
            return 0;
        }
    }
    
    cout << "NO\n";
    return 0;
}