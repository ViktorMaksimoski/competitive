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

    int v[n][3];
    for(int i=0; i<n; i++)
        for(int j=0; j<3; j++) cin >> v[i][j];

    ll dp[n][3];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<3; i++)
        dp[0][i] = v[0][i];

    for(int i=1; i<n; i++) {
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++) {
                if(j == k) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k] + v[i][j]);
            }
        }
    }
    
    cout << max({ dp[n-1][0], dp[n-1][1], dp[n-1][2] }) << '\n';
    return 0;
}