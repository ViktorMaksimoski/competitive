#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll sum = 0;
    ll inflation = 0;
    map<ll, int> occ;

    cin >> n;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        sum += x;
        occ[x]++;
    }

    int q;
    cin >> q;
    while(q--) {
        string t;
        cin >> t;

        if(t[0] == 'I') {
            int x;
            cin >> x;
            inflation += x;
        } else {
            int x, y;
            cin >> x >> y;
            int occ1 = occ[x - inflation];
            sum -= (occ1 * (x - inflation));
            occ[x - inflation] = 0;
            occ[y - inflation] += occ1;
            sum += (occ1 * (y - inflation));
        }

        cout << sum + inflation * n << '\n';
    }

    return 0;
}