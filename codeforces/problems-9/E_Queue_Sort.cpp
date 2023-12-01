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

    if(n == 1) {
        cout << 0 << '\n';
        return ;
    }

    int ans = 0;
    vector<int> pref(n, INT_MAX), suf(n, INT_MAX);
    pref[0] = v[0];
    for(int i=1; i<n; i++) pref[i] = min(pref[i-1], v[i]);
    suf[n-1] = v[n-1];
    for(int i=n-2; i>=0; i--) suf[i] = min(suf[i+1], v[i]);

    int j=0;
    while(j < n) {
        int mn = INT_MAX;
        if(j > 0) mn = min(mn, pref[j-1]);
        if(j < n-1) mn = min(mn, suf[j+1]);
        if(mn >= v[j]) break;
        j++; ans++;
    }

    if(j != n-1) {
        for(int i=j+1; i<n; i++) {
            if(v[i] < v[i-1]) {
                cout << -1 << '\n';
                return ;
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