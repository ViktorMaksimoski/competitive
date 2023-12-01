#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair
#define int long long

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

int exp(int a, int b) {
    if(a == 0) return b == 0;
    int ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        b >>= 1ll;
        a = (a * a) % mod;
    }
    return ans;
}

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;

    int base = exp(2, m) - 1;
    int ans = exp(base, n);
    cout << ans << '\n';
    return 0;
}