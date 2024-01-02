#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen( "angry.in", "r", stdin);
    freopen( "angry.out", "w", stdout);

    int n, ans = 1;
    cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;
    sort(v.begin(), v.end());

    auto go = [&](int pos, int step) {
        int l = pos;
        int d = 1;

        while(1) {
            int r = l;
            while(r + step < n && r + step >= 0 && abs(v[r+step] - v[l]) <= d) r += step;

            if(l == r) break;
            l = r, d++;
        }

        return abs(l - pos);
    };

    for(int i=0; i<n; i++)
        ans = max(ans, 1 + go(i, -1) + go(i, 1));
    cout << ans << '\n';
    return 0;
}