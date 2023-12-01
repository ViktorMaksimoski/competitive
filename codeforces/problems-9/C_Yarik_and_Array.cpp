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

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int &x : v) cin >> x;
    vector<pii> blocks;

    int ci=0, cj=0;
    for(int i=1; i<n; i++) {
        if((abs(v[i]) % 2) != (abs(v[i-1]) % 2)) {
            cj++;
        } else {
            blocks.push_back({ ci, cj });
            ci = i, cj = i;
        }
    }
    blocks.push_back({ ci, cj });

    ll ans = -1e18;
    
    for(pii &x : blocks) {
        ll sum = v[x.first];
        ll best = v[x.first];
        for(int i=x.first+1; i<=x.second; i++) {
            sum = max(sum+v[i], v[i]);
            best = max(best, sum);
        }
        ans = max(ans, best);
    }

    // for(pii &x : blocks)
    //     cout << x.first << " " << x.second << '\n';

    cout << ans << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}