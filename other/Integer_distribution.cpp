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

    int n;
    cin >> n;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    vector<ll> dp_min(1 << n, 1e12), dp_max(1 << n, 0);
    dp_min[0] = 0;
    dp_max[0] = 0;
    //min first
    for(int s=0; s<(1<<n); s++) {
        if(__builtin_popcount(s) & 1 || s == 0) continue;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if((s & (1 << i)) && (s & (1 << j))) {
                    int newMask = s ^ (1 << i);
                    newMask ^= (1 << j);
                    dp_min[s] = min(dp_min[s], dp_min[newMask] + (v[i] ^ v[j]));
                    dp_max[s] = max(dp_max[s], dp_max[newMask] + (v[i] ^ v[j]));
                }
            }
        }
    }

    cout << dp_min[(1 << n) - 1] << " " << dp_max[(1 << n) - 1] << '\n';
    return 0;
}