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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    setIO();

    int n, m;
    ll res = 0;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int &x : a) cin >> x, res += x;
    for(int &x : b) cin >> x;

    res *= m;

    sort(all(a));
    sort(all(b));

    if(a.back() > b[0]) {
        cout << -1 << '\n';
        return 0;
    }

    for(int i=1; i<m; i++) {
        res += (b[i] - a.back());
    }

    cout << res + (a[n-1] == b[0] ? 0 : b[0] - a[n-2]) << '\n';
    return 0;
}