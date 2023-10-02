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
const int maxn = 2e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    string s;
    cin >> s;

    int b=0;
    int ans = 0;

    vector<int> v;
    int curr = 0;

    for(int i=0; i<sz(s); i++) {
        if(s[i] == 'B') {
            b++;
            if(curr > 0) {
                v.push_back(curr);
                curr = 0;
            }
        } else {
            curr++;
        }
    }

    if(curr) v.push_back(curr);

    sort(rall(v));
    for(int i=0; i<min(sz(v), b); i++) ans += v[i];
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