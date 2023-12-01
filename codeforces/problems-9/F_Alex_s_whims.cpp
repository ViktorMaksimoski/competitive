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
    int n, q;
    cin >> n >> q;
    vector<int> d(q);
    for(int &x : d) cin >> x;

    int mx = 0;
    for(int i=0; i<q; i++) mx = max(mx, d[i]);

    for(int i=2; i<=mx; i++) cout << i-1 << " " << i << '\n';
    for(int i=mx+1; i<=n; i++) cout << mx << " " << i << '\n';

    int par = mx;
    for(int i=0; i<q; i++) {
        if(d[i] == par) {
            cout << "-1 -1 -1\n";
            continue;
        }

        cout << mx+1 << " " << par << " " << d[i] << '\n';
        par = d[i];
    }
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}