#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define pii pair<int, int>
#define pll pair<long long, long long>
#define debug(x) cout << #x << " = " << x << endl
#define pb push_back
#define eb emplace_back
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main() {
    setIO();

    int n, k;
    ll total = 0;
    int mx = 0;
    cin >> n >> k;
    vector<pii> v(n);
    for(pii &x : v) cin >> x.first >> x.second, total += x.second, mx = max(mx, x.first);

    if(total <= k) {
        cout << 1 << '\n';
        return 0;
    }

    sort(all(v));
    int ans = -1;

    int l=2, r=1e9+2;
    while(l <= r) {
        int mid = (l + r) / 2;

        ll day = 0;
        for(pii &x : v) {
            if(x.first < mid) continue;
            day += x.second;
        }

        if(day <= k) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;

    }

    cout << ans << '\n';
    return 0;
}