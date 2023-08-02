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

struct Project {
    int time;
    int group;
};

void solve() {
    int n, d, ans = 0;
    cin >> n >> d;
    vector<Project> v(n);
    for(Project &p : v) cin >> p.time >> p.group;

    vector<vector<ll> > dp(1 << n, vector<ll>(4));
    dp[0][3] = 1;

    for(int s=0; s<(1<<n); s++) {
        for(int t=0; t<4; t++) {
            for(int i=0; i<n; i++) {
                if(v[i].group == t) continue;
                if(!(s & (1 << i))) {
                    int newMask = s | (1 << i);
                    dp[newMask][v[i].group] += dp[s][t];
                    dp[newMask][v[i].group] %= mod;
                }
            }

            ll total = 0;
            for(int j=0; j<n; j++)
                if(s & (1 << j))
                    total += v[j].time;

            if(total == d) {
                ans += dp[s][t];
                ans %= mod;
            }
        }
    }
    
    cout << ans << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}