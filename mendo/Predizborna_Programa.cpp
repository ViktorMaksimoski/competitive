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

int n, x, y, k;

ll dp[21][21][21][21];

ll f(int curr, int good, int bad, int combo) {
    if(curr == n) return 1;
    if(dp[curr][good][bad][combo] != -1)
        return dp[curr][good][bad][combo];

    ll ans = f(curr+1, good, bad, combo);

    if(combo && good && bad)
        ans += f(curr+1, good-1, bad-1, combo-1);
    if(good)
        ans += f(curr+1, good-1, bad, combo);
    if(bad)
        ans += f(curr+1, good, bad-1, combo);

    return dp[curr][good][bad][combo] = ans;
}

int32_t main() {
    setIO();
    memset(dp, -1, sizeof(dp));

    cin >> n >> x >> y >> k;
    cout << f(0, x, y, k) << '\n';
    return 0;
}