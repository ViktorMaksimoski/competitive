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

    string s;
    cin >> s;

    for(int i=0; i<sz(s); i++) {
        if(s[i] == 'm' || s[i] == 'w') {
            cout << 0 << '\n';
            return 0;
        }
    }

    vector<ll> dp(sz(s));
    dp[0] = 1;

    for(int i=1; i<sz(s); i++) {
        dp[i] = dp[i-1];
        if(i > 1 && (s[i] == 'u' || s[i] == 'n') && s[i-1] == s[i])
            dp[i] += dp[i-2];
        else if(i == 1 && (s[i] == 'u' || s[i] == 'n') && s[i-1] == s[i])
            dp[i]++;
        dp[i] %= mod;
    }

    cout << dp[sz(s)-1] << '\n';
    return 0;
}