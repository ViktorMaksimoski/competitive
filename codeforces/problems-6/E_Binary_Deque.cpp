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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> prefix(n+1);

    for(int i=0; i<n; i++) {
        cin >> v[i];
        prefix[i+1] = v[i] + prefix[i];
    }

    if(prefix[n] < k) {
        cout << -1 << '\n';
        return ;
    }

    int ans = 1e9;

    for(int i=0; i<n; i++) {
        int l=i, r=n-1;
        int ans2 = n+1;

        while(l <= r) {
            int mid = (l + r) / 2;
            if(prefix[mid+1] - prefix[i] <= k) {
                ans2 = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

        if(ans2 == n+1) continue;
        if(prefix[ans2+1] - prefix[i] != k) continue;

        ans = min(ans, i + (n - ans2 - 1));
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