#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    if(name != "") setUSA(name);
}

ll dp[int(1e3+2)][int(1e3+2)][2];
int main() {
    setIO();

    string s, t;
    cin >> t >> s;
    int n = s.size(), m = t.size();

    dp[0][0][0] = 0;
    dp[0][0][1] = (s[0] == t[0]);

    for (int i=1; i<n; i++) {
        dp[i][0][1] = (s[i] == t[0]);
        dp[i][0][0] = (dp[i-1][0][1] + dp[i-1][0][0]) % mod;
    }

    for (int i=1; i<n; i++) {
        for (int j=1; j<=i; j++) {
            dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % mod;
            if (s[i] == t[j])
                dp[i][j][1] = dp[i-1][j-1][0] % mod;
        }
    }
    cout << (dp[n-1][m-1][0] + dp[n-1][m-1][1]) % mod << '\n';
    return 0;
}