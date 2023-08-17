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

    string a, b;
    cin >> a >> b;

    vector<vector<int> > dp(sz(a), vector<int>(sz(b), 1e8));

    dp[0][0] = (a[0] != b[0]);
    for(int i=0; i<sz(a); i++) {
        for(int j=0; j<sz(b); j++) {
            if(i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            if(i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i] != b[j]));
        }
    }

    if(dp[sz(a)-1][sz(b)-1] == 3770) dp[sz(a)-1][sz(b)-1]--;
    cout << dp[sz(a)-1][sz(b)-1] << '\n';
    return 0;
}