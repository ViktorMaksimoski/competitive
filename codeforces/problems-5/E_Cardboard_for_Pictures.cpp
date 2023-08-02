#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
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
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    int n;
    ull c;
    cin >> n >> c;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    ll ans = 0;
    int l=1, r=1e9;
    while(l <= r) {
        int mid = (l + r) / 2;
        ull total = 0;
        for(int &x : v) {
            ull len = x + 2*mid;
            if(len > 1e9) {
                total = c + 1;
                break;
            }
            total += (len * len);
            if(total > c) break;
        }

        if(total == c) {
            ans = mid;
            break;
        } else if(total > c) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
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