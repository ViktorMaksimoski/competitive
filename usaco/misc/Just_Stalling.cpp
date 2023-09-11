#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using ll = long long;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    sort(rall(a));
    sort(all(b));

    ll ans = 1;
    for(int i=0; i<n; i++) {
        int pos  = b.end() - lower_bound(all(b), a[i]);
        ans *= (pos - i);
    }

    cout << ans << '\n';
    return 0;
}