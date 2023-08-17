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

struct Item { int c, t; };

int32_t main() {
    setIO();

    int n;
    cin >> n;
    vector<Item> v(n);
    for(Item &i : v) cin >> i.c >> i.t;
    int w;
    cin >> w;

    ll dp[n+1][w+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=w; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= v[i-1].t)
                dp[i][j] = max(dp[i][j], v[i-1].c + dp[i-1][j-v[i-1].t]);
        }
    }

    cout << dp[n][w] << '\n';
    return 0;
}