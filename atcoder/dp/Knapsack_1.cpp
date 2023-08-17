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

struct Item { int w, v; };

int32_t main() {
    setIO();

    int n, w;
    cin >> n >> w;
    vector<Item> items(n);
    for(Item &i : items) cin >> i.w >> i.v;

    ll dp[n+1][w+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=w; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= items[i-1].w)
                dp[i][j] = max(dp[i][j], dp[i-1][j-items[i-1].w] + items[i-1].v);
        }
    }

    cout << dp[n][w] << '\n';
    return 0;
}