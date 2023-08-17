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

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    auto meet = [&](int l, int r) -> vector<int> {
        int len = r - l + 1;
        vector<int> res;

        for(int i=0; i<(1<<len); i++) {
            ll sum = 0;
            for(int j=0; j<len; j++) {
                if(i & (1 << j)) sum += (v[l + j] % m);
            }
            res.push_back(sum % m);
        }

        return res;
    };

    vector<int> left = meet(0, n/2-1);
    vector<int> right = meet(n/2, n-1);
    sort(all(left));
    sort(all(right));

    ll ans = 0;
    for(int &x : left) {
        ll can = m - x - 1;
        ll mx = 0;

        int l=0, r=sz(right)-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(right[mid] > can) {
                r = mid - 1;
            } else {
                l = mid + 1;
                mx = right[mid];
            }
        }

        ans = max(ans, x + mx);
    }

    cout << ans << '\n';
    return 0;
}