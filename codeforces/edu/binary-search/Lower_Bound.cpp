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

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    while(q--) {
        int x;
        cin >> x;
        int ans = 0;

        int l=0, r=n-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(v[mid] <= x) {
                ans = mid + 1;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}