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

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

int32_t main() {
    setIO();
    setUSA("snakes");

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    ll dp[n+1][k+1];
    ll total = 0;
    int mx = 0;
    for(int i=0; i<n+1; i++)
        for(int j=0; j<k+1; j++)
            dp[i][j] = 1e11;

    for(int i=0; i<n; i++) {
        mx = max(mx, v[i]);
        total += v[i];
        dp[i+1][0] = mx * (i + 1);
        for(int j=1; j<=k; j++) {
            int x = v[i];
            for(int k=i-1; k>=0; k--) {
                dp[i+1][j] = min(dp[i+1][j], dp[k+1][j-1] + 1ll * x * (i - k));
                x = max(x, v[k]);
            }
        }
    }

    cout << dp[n][k] - total << '\n';
    return 0;
}