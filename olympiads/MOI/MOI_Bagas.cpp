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

int n, x;
vector<pii> v;
int dp[1<<16];
bool can[1<<16];

int f(int mask) {
    if(dp[mask] != -1) return dp[mask];
    if(mask == 0) return 0;

    int ans = 1e9;

    for(int s=mask; s>0; s=(s-1)&mask) {
        if(!can[s]) continue;
        ans = min(ans, f(mask ^ s) + __builtin_popcount(s) - 1);
    }

    return dp[mask] = ans;
}

int32_t main() {
    setIO();
    memset(dp, -1, sizeof(dp));
    memset(can, 1, sizeof(can));

    cin >> n >> x;
    v.clear();
    v.resize(n);

    for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;

    for(int s=0; s<(1<<n); s++) {
        vector<int> v2;
        for(int i=0; i<n; i++) {
            if(s & (1 << i)) {
                v2.push_back(v[i].first);
                v2.push_back(v[i].second);
            }
        }
        sort(all(v2));
        for(int i=0; i<sz(v2); i+=2) {
            if(v2[i+1] - v2[i] > x) {
                can[s] = 0;
                break;
            }
        }
    }


    int ans = f((1<<n)-1);
    cout << (ans == 1e9 ? -1 : ans) << '\n';
    return 0;
}