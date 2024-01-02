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

short N, K, S;
int dp[11][1001][1001];
vector<int> v;

int f(int pos, int left, int time) {
    if(time == S+1) return 0;
    if(dp[pos][left][time] != -1) return dp[pos][left][time];

    //stay here
    int ans = f(pos, left, time+1);
    //move 1 pos to the left
    if(pos - 1 >= 0 && left)
        ans = max(ans, f(pos-1, left-1, time+1));
    if(pos + 1 < N && left)
        ans = max(ans, f(pos+1, left-1, time+1));

    //check if you can take the current ball
    if(abs(pos - v[time]) <= 1 && left >= abs(pos - v[time]))
        ans = max(ans, 1 + f(v[time], left - abs(pos - v[time]), time+1));    

    return dp[pos][left][time] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> N >> K >> S;
    v.clear();
    v.resize(S+1);
    for(int i=1; i<=S; i++) cin >> v[i], v[i]--;
    cout << f(0, K, 1) << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}