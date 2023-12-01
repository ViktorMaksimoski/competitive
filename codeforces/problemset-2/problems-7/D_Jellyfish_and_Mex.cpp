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

void solve() {
    int n;
    cin >> n;

    map<int, int> cnt;
    vector<int> v(n);
    for(int &x : v) cin >> x, cnt[x]++;
    sort(all(v));

    //find current mex (o1: mex is <= 5000)
    int curr = 0;
    for(int i=0; i<=5001; i++) {
        if(!cnt[i]) {
            curr = i;
            break;
        }
    }

    //e sega dp
    //koga ke se izvadi nekoj mex od igra, noviot ke bide pogolem
    vector<ll> dp(curr+1, 1e18);
    dp[curr] = 0;
    
    for(int i=curr; i>=0; i--)
        for(int j=0; j<i; j++)
            dp[j] = min(dp[j], dp[i] + (cnt[j] - 1) * i + j);

    cout << dp[0] << '\n';

}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}