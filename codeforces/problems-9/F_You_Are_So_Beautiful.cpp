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

    vector<int> v(n);
    for(int &x : v) cin >> x;
    map<int, int> cnt;
    ll ans = 0, ans2 = 0;

    vector<int> v2(n), v3(n);
    for(int i=0; i<n; i++) {
        if(!cnt.count(v[i])) v2[i] = 1;
        cnt[v[i]]++;
    }

    cnt.clear();
    for(int i=n-1; i>=0; i--) {
        if(!cnt.count(v[i])) v3[i] = 1;
        cnt[v[i]]++;
    }

    for(int i=0; i<n; i++) {
        if(v2[i]) ans2++;
        if(v3[i]) ans += ans2;
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