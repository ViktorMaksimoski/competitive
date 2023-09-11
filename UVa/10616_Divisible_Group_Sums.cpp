#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define int long long

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

int32_t main() {
    setIO();

    int n, q;
    int id = 1;
    while(cin >> n >> q) {
        if(!n && !q) break;
        vector<int> v(n);
        for(int &x : v) cin >> x;

        cout << "SET " << id++ << ": \n";

        for(int qnum=1; qnum<=q; qnum++) {
            int d, m;
            cin >> d >> m;
            
            cout << "QUERY " << qnum << ": ";

            int dp[n+1][m+1][d];
            memset(dp, 0, sizeof(dp));
            dp[0][0][0] = 1;

            for(int i=1; i<=n; i++) {
                for(int j=0; j<=m; j++) {
                    for(int k=0; k<d; k++) {
                        dp[i][j][k] += dp[i-1][j][k];
                        int newK = (k + v[i-1]) % d;
                        if(newK < 0) newK += d;
                        if(j > 0) dp[i][j][k] += dp[i-1][j-1][newK];
                    }
                }
            }

            cout << dp[n][m][0] <<  '\n';
        }
    }

    return 0;
}