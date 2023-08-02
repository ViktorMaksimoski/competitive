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

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

void setIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int dp[int(1e5 + 5)][3][21];

int main() {
    setIO();
    setUSA("hps");

    int n, m;
    cin >> n >> m;

    vector<char> v(n);
    for(char &ch : v) cin >> ch;

    //H(0) > S(1)
    //S(1) > P(2)
    //P(2) > H(0) 

    //dp[i][j][k] - we are at game i, we play gesture j and we've made k changes
    //so far

    map<char, int> val;
    val['H'] = 0, val['S'] = 1, val['P'] = 2;
    for(int i=0; i<n; i++) {
        for(int k=0; k<=m; k++) {
            for(int j=0; j<3; j++) {
                dp[i][j][k] += (val[v[i]] == j);
                if(j != 0 && k < m)
                    dp[i+1][0][k+1] = max(dp[i+1][0][k+1], dp[i][j][k]);
                if(j != 1 && k < m)
                    dp[i+1][1][k+1] = max(dp[i+1][1][k+1], dp[i][j][k]);
                if(j != 2 && k < m)
                    dp[i+1][2][k+1] = max(dp[i+1][2][k+1], dp[i][j][k]);
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
            }
        }
    }

    int ans = max({ dp[n-1][0][m], dp[n-1][1][m], dp[n-1][2][m] });
    cout << ans << '\n';
    return 0;
}