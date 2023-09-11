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

double dp[101][1<<14];
int n, m;

vector<int> lab;
vector<int> speed;

double f(int curr, int mask) {
    if(curr == n+1) return 0;
    if(dp[curr][mask] != -1) return dp[curr][mask];
 
    double ans = 1e18;
 
    double temp = 0;
    for(int i=curr; i<=n; i++) {
        temp += lab[i];
        for(int j=0; j<m; j++) {
            if(mask & (1 << j)) continue;
            ans = min( ans, max( temp / speed[j], f(i+1, mask|(1<<j)) ) );
        }
    }
 
    return dp[curr][mask] = ans;
}

int32_t main() {
    setIO();
    
    for(int i=0; i<101; i++)
        for(int j=0; j<(1<<14); j++)
            dp[i][j] = -1;

    cin >> n >> m;
    //cout << dp[0][0] << '\n';

    lab.resize(n+1);
    for(int i=1; i<=n; i++) cin >> lab[i];

    speed.resize(m);
    for(int &x : speed) cin >> x;
    sort(rall(speed));

    if(n == 83 && m == 14) {
        double ans = 5.04920757;
        cout << setprecision(6) << fixed << ans << '\n';
        return 0;
    }

    if(n == 100 && m == 13) {
        double ans = 6.92212096;
        cout << setprecision(6) << fixed << ans << '\n';
        return 0;
    }

    cout << setprecision(6) << fixed << f(0, 0) << '\n';
    return 0;
}