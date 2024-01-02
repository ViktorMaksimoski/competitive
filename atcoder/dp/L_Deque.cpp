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

int n;
vector<int> v;
ll dp[3001][3001][2];

ll f(int l, int r, int x) {
    if(dp[l][r][x] > -1e15) return dp[l][r][x];
    if(l > r) return 0;

    if(x == 0)
        return dp[l][r][x] = max(v[l] + f(l+1, r, !x), v[r] + f(l, r-1, !x));
    return dp[l][r][x] = min(f(l+1, r, !x) - v[l], f(l, r-1, !x) - v[r]);
}

int32_t main() {
    setIO();
    for(int i=0; i<3001; i++)
        for(int j=0; j<3001; j++)
            for(int k=0; k<2; k++) dp[i][j][k] = -1e15;
   
    cin >> n;
    v.resize(n+1);
    for(int i=0; i<n; i++) cin >> v[i];

    cout << f(0, n-1, 0);
    return 0;
}