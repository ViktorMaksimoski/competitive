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

int n, m;
int mat[101][101];
int per_country[16];
int dp[101][1<<16];
int ans = 0;

int f(int guide, int mask) {
    if(mask == (1 << m) - 1) return 0;
    if(guide == n) return 1e9+1;
    if(dp[guide][mask] != -1) return dp[guide][mask];

    int res = 1e9+1;
    res = min(res, f(guide+1, mask));

    for(int i=0; i<m; i++) {
        if(mask & (1 << i)) continue;
        int newMask = mask | (1 << i);
        int res2 = per_country[i] - mat[guide][i];

        res = min(res, res2 + f(guide+1, newMask));
    }

    return dp[guide][mask] = res;
}

int32_t main() {
    setIO();

    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    memset(per_country, 0, sizeof(per_country));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> mat[i][j], per_country[j] += mat[i][j];
    
    cout << f(0, 0) << '\n';
    return 0;
}