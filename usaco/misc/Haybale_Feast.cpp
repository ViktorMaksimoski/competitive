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

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

int32_t main() {
    setIO();
    setUSA("hayfeast");

    int n;
    ll m;
    cin >> n >> m;

    vector<pii> v(n);
    for(pii &x : v) cin >> x.first >> x.second;

    multiset<int> ms;
    int ans = 1e9+1;
    ll sum = 0;
    for(int i=0, j=0; j<n; i++) {
        while(j < n && sum < m) {
            sum += v[j].first;
            ms.insert(v[j].second);
            j++;
        }

        ans = min(ans, *ms.rbegin());

        sum -= v[i].first;
        ms.erase(ms.find(v[i].second));
    }

    cout << ans << '\n';
    return 0;
}