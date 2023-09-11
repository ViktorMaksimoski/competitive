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

    int w, h;
    cin >> w >> h;

    int n;
    cin >> n;

    vector<pii> v(n);
    for(pii &x : v) cin >> x.first >> x.second;

    vector<vector<ll> > dp(w+1, vector<ll>(h+1, 0));

    for(int i=1; i<=w; i++)
        for(int j=1; j<=h; j++)
            dp[i][j] = i * j;

    for(pii &x : v)
        dp[x.first][x.second] = 0;

    for(int i=1; i<=w; i++) {
        for(int j=1; j<=h; j++) {
            for(int k=1; k<=i; k++)
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j]);
            for(int k=1; k<=j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k]);
        }
    }

    cout << dp[w][h] << '\n';
    return 0;
}