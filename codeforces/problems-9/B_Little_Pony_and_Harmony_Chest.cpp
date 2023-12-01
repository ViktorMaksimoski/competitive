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

int dp[101][1<<17], last[101][1<<17];
int32_t main() {
    setIO();

    int n;
    cin >> n;

    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];

    vector<int> mask(61, 0);
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

    for(int i=2; i<=60; i++)
        for(int j=0; j<17; j++)
            if(i % primes[j] == 0)
                mask[i] |= (1 << j);

    for(int i=0; i<=n; i++)
        for(int j=0; j<(1<<17); j++) dp[i][j] = 10000;
    dp[0][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int s=0; s<(1<<17); s++) {
            dp[i][s] = dp[i-1][s] + v[i] - 1;
            last[i][s] = 1;
            for(int j=2; j<=2*v[i]; j++) {
                if((s & mask[j]) != mask[j]) continue;
                if(dp[i][s] > dp[i-1][s^mask[j]] + abs(v[i] - j)) {
                    dp[i][s] = dp[i-1][s^mask[j]] + abs(v[i] - j);
                    last[i][s] = j;
                }
            }
        }
    }

    int curr = 0;
    for(int i=1; i<(1<<17); i++)
        if(dp[n][i] < dp[n][curr]) curr = i;
        
    vector<int> ans;

    for(int i=n; i>0; i--) {
        ans.push_back(last[i][curr]);
        curr -= mask[last[i][curr]];
    }

    reverse(all(ans));
    for(int &x : ans) cout << x << " ";
    return 0;
}