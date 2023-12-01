#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define int long long

using namespace std;
using ll = long long;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<ll> prefix(n+1);

    for(int &x : v) cin >> x;
    sort(all(v));
    for(int i=1; i<=n; i++) prefix[i] = prefix[i-1] + v[i-1];

    ll ans = v.back() - v[0];

    int lp=0, rp=ans;
    while(lp <= rp) {
        auto mid = lp + (rp - lp) / 2;
        bool ok = false;
        
        for(int i=0; i<n; i++) {
            ll left = prefix[i+1];
            auto pt = upper_bound(all(v), v[i] + mid) - v.begin();
            ll right = prefix[n] - prefix[pt];

            ll moves = 1ll * (i + 1) * v[i] - left + right - 1ll * (n - pt) * (v[i] + mid);
            if(moves <= k) ok = true;
            if(ok) break;
        }

        if(ok) {
            ans = mid;
            rp = mid - 1;
        } else {
            lp = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}