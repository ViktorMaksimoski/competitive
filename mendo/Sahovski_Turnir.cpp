#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k=-1;
    cin >> n;

    int x = n;
    while(x) x /= 2, k++;

    ll ans = 0;
    int depth = k, total = 0, now = 1;
    for(int i=0; i<n; i++) {
        cin >> x;
        if(!i) ans += x;

        ans += 1ll * x * (depth - 1);
        total++;

        if (total == now) {
            depth--;
            now *= 2;
        }
    }

    cout << ans << '\n';
    return 0;
}