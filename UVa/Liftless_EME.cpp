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

int main() {
    setIO();

    string s;
    while(cin >> s) {
        int n, m;
        cin >> n >> m;

        int graph[n-1][m][m];
        
        for(int i=0; i<n-1; i++)
            for(int j=0; j<m; j++)
                for(int k=0; k<m; k++)
                    cin >> graph[i][j][k];

        ll dp[n][m];
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) dp[i][j] = 1e12;
        memset(dp[0], 0, sizeof(dp[0]));

        ll ans = 1e12;
        for(int k=1; k<n; k++) {
            for(int i=0; i<m; i++) {
                for(int j=0; j<m; j++) {
                    dp[k][i] = min(dp[k][i], dp[k-1][j] + 2 + graph[k-1][j][i]);
                    if(k == n-1) ans = min(ans, dp[k][i]);
                }
            }
        }

        cout << s << '\n';
        cout << ans << '\n';
    }

    return 0;
}