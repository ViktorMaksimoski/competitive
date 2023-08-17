#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()

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

    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);

    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    for(int i=0; i<n; i++) c[i] = a[i] - b[i];
    sort(all(c));

    // for(int &x : c) cout << x << " ";
    // cout << '\n';

    ll ans = 0;

    for(int i=0; i<n; i++) {
        if(c[i] < 0) {
            continue;
        } else if(c[i] > 0) {
            int pos = lower_bound(all(c), 1-c[i]) - c.begin();
            ans += (i - pos);
            //cout << i << ", " << pos << '\n';
        }
    }

    cout << ans << '\n';
    return 0;
}