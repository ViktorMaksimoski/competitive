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

//MENDO - Olimpiski igri copy paste
int32_t main() {
    setIO();

    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;
    vector<vector<int> > dp(n, vector<int>(3, 0));

    dp[0][0] = 0;
    dp[0][1] = (v[0] == 1 || v[0] == 3);
    dp[0][2] = (v[0] == 2 || v[0] == 3);
    for(int i=1; i<n; i++) {
        dp[i][0] = *max_element(all(dp[i-1]));
        if(v[i] == 1) {
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + 1;
        } else if(v[i] == 2) {
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + 1;
        } else if(v[i] == 3) {
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + 1;
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + 1;
        }
    }

    cout << *max_element(all(dp[n-1])) << '\n';
    return 0;
}