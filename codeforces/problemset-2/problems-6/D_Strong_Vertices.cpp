#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()

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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    ll mx = -1e18;
    for(int i=0; i<n; i++) {
        mx = max(mx, 1ll * (a[i] - b[i]));
    }

    vector<int> ans;

    for(int i=0; i<n; i++) {
        if(a[i] - b[i] == mx) ans.push_back(i+1);
    }

    cout << ans.size() << '\n';
    for(int &x : ans) cout << x << " ";
    cout << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}