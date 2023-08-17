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

    int n;
    cin >> n;
    vector<int> v(n);
    
    int table[n+1][LOG];
    int bin_log[n+1];
    for(int i=0; i<n; i++) cin >> v[i], table[i][0] = v[i];

    bin_log[1] = 0;
    for(int i=2; i<=n; i++)
        bin_log[i] = bin_log[i/2] + 1;

    for(int j=1; j<LOG; j++)
        for(int i=0; i+(1<<j)-1<n; i++) 
            table[i][j] = max(table[i][j-1], table[i+(1<<(j-1))][j-1]);

    auto query = [&](int l, int r) {
        if(l > r) swap(l, r);
        int len = r - l + 1;
        int k = bin_log[len];

        return max(
            table[l][k],
            table[r-(1<<k)+1][k]
        );
    };

    int m, x, y;
    cin >> m >> x >> y;

    ll ans = query(x, y);

    for(int i=1; i<m; i++) {
        x += 7;
        y += 11;
        x %= (n-1);
        y %= n;

        ans += query(x, y);
    }

    cout << ans << '\n';
    return 0;
}