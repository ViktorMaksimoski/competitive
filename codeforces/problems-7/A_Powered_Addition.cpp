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

int getLog(int x) {
    int ans = 0;
    while(x) {
        ans++; 
        x /= 2;
    }
    return ans;
}

void solve() {
    int n, ans = 0;
    cin >> n;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    vector<int> need;
    int last = v[0];
    for(int i=1; i<n; i++) {
        if(v[i] < last) {
            need.push_back(last - v[i]);
        } else {
            last = v[i];
        }
    }

    // for(int &x : need) cout << x << " ";
    // cout << '\n';
    for(int &x : need) ans = max(ans, getLog(x));
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