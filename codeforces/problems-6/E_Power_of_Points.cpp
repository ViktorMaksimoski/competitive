#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define int long long
using namespace std;
using ll = long long;
using pii = pair<int, int>;

// NAJGOLEM IDIOT SUM ZASTO OVAA NE JA RESIV NA KAMPOT
// GLUPAK NA DECENIJATA!!!!!!!!!!!
void solve() {
    int n;
    cin >> n;
    vector<pii> v(n);
    vector<ll> ans(n);

    ll prefix = 0, suffix = 0;
    
    for(int i=0; i<n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(all(v));
    for(int i=1; i<n; i++)
        suffix += (v[i].first - v[0].first + 1);

    ans[v[0].second] = prefix + suffix + 1;

    for(int i=1; i<n; i++) {
        prefix += (v[i].first - v[i-1].first + 1);
        prefix += (i - 1) * (v[i].first - v[i-1].first);

        suffix -= (v[i].first - v[i-1].first + 1);
        suffix -= (n - i - 1) * (v[i].first - v[i-1].first);

        ans[v[i].second] = prefix + suffix + 1;
    }

    for(ll &x : ans) cout << x << " ";
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}