#include <bits/stdc++.h>
 
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << ": " << x << '\n'
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
const int mod = 1e9 + 7;
const int LOG = 20;
 
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
 
int32_t main() {
    setIO();
 
    int x;
    cin >> x;
    vector<int> v(x);
    for(int &a : v) cin >> a;
 
    int n = x/3;
 
    vector<ll> l(x+1, 0), r(x+1, 0);
    multiset<ll> ms;
 
    for(int i=1; i<=x; i++) {
        if(i <= n) {
            l[i] = l[i-1] + v[i-1];
            ms.insert(v[i-1]);
        } else {
            l[i] = l[i-1];
            if(v[i-1] > *ms.begin()) {
                l[i] += v[i-1];
                l[i] -= *ms.begin();
                ms.erase(ms.begin());
                ms.insert(v[i-1]);
            }
        }
    }
 
    ms.clear();
    for(int i=x; i>=1; i--) {
        if(i == x) {
            r[i] = v[i-1];
            ms.insert(v[i-1]);
        } else if(i >= x-n+1) {
            r[i] = r[i+1] + v[i-1];
            ms.insert(v[i-1]); 
        } else {
            r[i] = r[i+1];
            if(v[i-1] < *ms.rbegin()) {
                r[i] -= *ms.rbegin();
                r[i] += v[i-1];
                ms.erase((--ms.end()));
                ms.insert(v[i-1]);
            }
        }
    }
 
    ll ans = -1e15;
    for(int i=n; i<=x-n; i++)
        ans = max(ans, l[i] - r[i+1]);
    cout << ans << '\n';
    return 0;
}