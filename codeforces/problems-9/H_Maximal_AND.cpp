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
    int n, k;
    cin >> n >> k;

    vector<int> cnt(33, 0);
    ll ans = 0;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        for(int j=0; j<=30; j++) {
            if(x & (1 << j)) {
                cnt[j]++;
            }
        }
    }

    for(int j=30; j>=0; j--) {
        if(k >= (n - cnt[j])) {
            k -= (n - cnt[j]);
            cnt[j] = n;
        }
    }

    for(int j=30; j>=0; j--) {
        if(cnt[j] == n) ans |= (1ll << j);
    }

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