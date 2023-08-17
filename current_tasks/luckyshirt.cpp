#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
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

    int n, i, k;
    cin >> n >> k >> i;

    ld ans = pow((i - 1) * 1.0 / n, k) * i;
    for(int j=i+1; j<=n; j++) {
        ans += (j + 1) * 1.0 / 2 * pow((j) * 1.0/n, k) - pow((j-1) * 1.0/n, k);
    }

    cout << fixed << setprecision(8) << ans << '\n';
    return 0;
}