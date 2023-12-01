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

string s;
int n;
int dp[501][501];

int32_t main() {
    setIO();
    
    cin >> s;
    n = sz(s);

    for(int j=0; j<=n-1; j++) {
        for(int i=0; i<n-j; i++) {
            dp[i][i+j] = dp[i+1][i+j] + 1;
            for(int k=i+1; k<=i+j; k++)
                if(s[i] == s[k])
                    dp[i][i+j] = min(dp[i][i+j], dp[i+1][k-1] + dp[k+1][i+j]);
        }
    }

    cout << dp[0][n-1] << '\n';
    return 0;
}