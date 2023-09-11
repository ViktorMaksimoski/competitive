#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define int long long

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

    int x, y;
    cin >> x >> y;

    int l = (20 * x + 18) / 19;
    int r = min(y, (10 * x) / 9);

    if(l % 5 > 0) l += 5 - (l % 5);
    if(r % 5 > 0) r -= (r % 5);

    if(l > r) {
        cout << 0 << '\n';
        return 0;
    }

    cout << (r - l) / 5 + 1 << '\n';
    return 0;
}