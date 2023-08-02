#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define pii pair<int, int>
#define pll pair<long long, long long>
#define debug(x) cout << #x << " = " << x << endl
#define pb push_back
#define eb emplace_back
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main() {
    setIO();

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int &x : v) cin >> x;

        //dp[i][0] - me
        //dp[i][1] - my friend
        vector<vector<int> > dp(n+1, vector<int>(2, 1e9));
        dp[0][1] = 0;

        //our friend played only one move
        //dp[i+1][0] = min(dp[i+1][0], dp[i][1] + v[i]);
        //he played both moves
        //dp[i+2][0] = min(dp[i+2][0], dp[i][1] + v[i] + v[i+1]);
        //I played one move
        //dp[i+1][1] = min(dp[i+1][1], dp[i][0]);
        //I played both moves
        //dp[i+2][1] = min(dp[i+2][1], dp[i][0]);
        for(int i=0; i<n; i++) {
            dp[i+1][0] = min(dp[i+1][0], dp[i][1] + v[i]);
            dp[i+1][1] = min(dp[i+1][1], dp[i][0]);

            if(i <= n-2) {
                dp[i+2][0] = min(dp[i+2][0], dp[i][1] + v[i] + v[i+1]);
                dp[i+2][1] = min(dp[i+2][1], dp[i][0]);
            }
        }
        

        cout << min(dp[n][0], dp[n][1]) << '\n';
    }

    return 0;
}