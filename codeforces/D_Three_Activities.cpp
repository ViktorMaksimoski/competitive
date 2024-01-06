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

    vector<pii> a(n), b(n), c(n);

    for(int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    for(int i=0; i<n; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }

    for(int i=0; i<n; i++) {
        cin >> c[i].first;
        c[i].second = i;
    }

    sort(rall(a));
    sort(rall(b));
    sort(rall(c));

    ll ans = 0;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++) {
                if(a[i].second == b[j].second) continue;
                if(a[i].second == c[k].second) continue;
                if(b[j].second == c[k].second) continue;
                ans = max(ans, 1ll * (a[i].first + b[j].first + c[k].first));
            }
        }
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