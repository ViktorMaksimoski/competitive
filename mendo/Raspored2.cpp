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

    int n, x, y;
    cin >> n >> x >> y;
    int total = 0;

    vector<int> v(n);
    for(int &el : v) cin >> el, total += el;
    sort(all(v));

    if(n * y < total || n * x > total) {
        cout << -1 << '\n';
        return 0;
    }

    ll ans1 = 0, ans2 = 0;

    for(int &el : v) {
        if(el < x) ans1 += (x - el);
        if(el > y) ans2 += (el - y);
    }

    cout << max(ans1, ans2) << '\n';
    return 0;
}