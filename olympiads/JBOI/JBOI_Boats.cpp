#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
//#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    setIO();

    int n;
    cin >> n;
    vector<pii> v(n);
    for(pii &x : v) cin >> x.first >> x.second;

    sort(all(v), [&](pii a, pii b) {
        return a.second < b.second;
    });

    int ans = 1;
    int l=v[0].second-v[0].first, r=v[0].second;

    for(int i=1; i<n; i++) {
        if(v[i].second >= r) {
            l = r;
            r = max(r + v[i].first, v[i].second);
            ans++;
        }
        r = min(r, max(v[i].second, v[i].first + l));
    }

    cout << ans << '\n';
    return 0;
}