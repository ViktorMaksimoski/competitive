#include <bits/stdc++.h>
using namespace std;

bitset<300001> bs;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, total = 0, best = 0;
    cin >> n;

    vector<int> v(n);
    for(int &x : v) cin >> x, total += x;

    bs[0] = 1;
    for(int &x : v) bs |= (bs << x);
    for(int i=1; i<=total/2; i++) best = (bs[i] ? i : best);

    cout << best << " " << total - best << '\n';
    return 0;
}