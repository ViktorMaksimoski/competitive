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
ll dp[21][21][42];

ll f(int curr, int in_stack, int moves) {
    if(!in_stack && moves == 2*n) return 1;
    if(dp[curr][in_stack][moves] != -1) return dp[curr][in_stack][moves];

    ll ans = 0;

    if(in_stack > 0) ans += f(curr, in_stack-1, moves+1);
    if(curr < n+1) ans += f(curr+1, in_stack+1, moves+1);

    return dp[curr][in_stack][moves] = ans;
}

int32_t main() {
    setIO();
    memset(dp, -1, sizeof(dp));

    cin >> n;

    cout << f(1, 0, 0) << '\n';
    return 0;
}