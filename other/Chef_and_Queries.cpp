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

const ll mod = 1LL << 32;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bitset<(1ll << 31)> bs;
int32_t main() {
    setIO();

    ll q, s, a, b;
    cin >> q >> s >> a >> b;

    ll sum = 0;
    while (q--) {
		if (s % 2 == 1 && !bs[s/2]) {
			bs[s/2] = 1;
			sum += (s / 2);
		} else if (s % 2 == 0 && bs[s/2]) {
			bs[s/2] = 0;
			sum -= (s / 2);
		}

		s = (a * s) % mod;
        s += b;
        s %= mod;
	}

    cout << sum << '\n';
    return 0;
}