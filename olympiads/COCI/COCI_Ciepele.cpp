#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    sort(all(a));
    sort(all(b));

    if(n == m) {
        int ans = 0;
        for(int i=0; i<n; i++)
            ans = max(ans, abs(a[i] - b[i]));
        cout << ans << '\n';
    } else {
        if(n > m) swap(a, b);
        int ans = 1e9;
        int l=0, r=max(b.back() - a[0], a.back() - b[0]);

        while(l <= r) {
            int mid = (l + r) / 2;
            int i=0, j=0, pairs = 0;

            while(i < min(n, m) && j < max(n, m)) {
                if(abs(a[i] - b[j]) <= mid) {
                    pairs++, i++, j++;
                } else if(a[i] - b[j] > mid) {
                    j++;
                } else if(a[i] - b[j] < mid) {
                    i++;
                }
            }

            if(pairs == min(n, m)) {
                ans = mid;
                r = mid - 1;
            } else if(pairs < min(n, m)) {
                l = mid + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}