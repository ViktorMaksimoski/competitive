#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct Vrba { 
    int v, s;

    bool operator<(Vrba &b) {
        if(s == b.s)
            return (v < b.v);
        return (s < b.s);
    }    
};

int32_t main() {
    setIO();

    int n, t;
    cin >> n >> t;
    ll begV = 0, totalS = 0;
    vector<Vrba> v(n);
    for(Vrba &x : v) cin >> x.v >> x.s, begV += x.v, totalS += x.s;

    vector<vector<ll> > dp(n+1, vector<ll>(n+1, 0));
    sort(all(v));
    int ans = -1;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            dp[i][j] = dp[i-1][j];
            if(j)
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + v[i-1].v + v[i-1].s * j * 1ll);
            if(i == n) {
                ll curr = begV + totalS * j - dp[n][j];
                if(curr < t) {
                    ans = j;
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}