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

int32_t main() {
    setIO();

    int n;

    while(true) {
        cin >> n;
        if(!n) break;
        
        vector<int> v(n);
        for(int &x : v) cin >> x;

        ll ans = v[0];
        ll curr = v[0];

        for(int i=1; i<n; i++) {
            curr = max(curr + v[i], 1ll * v[i]);
            ans = max(ans, curr);
        }

        if(ans <= 0) {
            cout << "Losing streak.\n";
        } else {
            cout << "The maximum winning streak is " << ans << ".\n";
        }
    }

    return 0;
}