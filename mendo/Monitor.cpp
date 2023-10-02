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

    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;

    vector<int> hor(n+1, 0), ver(m+1, 0);

    int p;
    cin >> p;
    for(int i=0; i<p; i++) {
        int r, c, t;
        cin >> r >> c >> t;

        if(t == 1) {
            hor[r] = 1;
        } else {
            ver[c] = 1;
        }
    }

    for(int i=1; i<=n; i++) hor[i] += hor[i-1];
    for(int i=1; i<=m; i++) ver[i] += ver[i-1];

    int ans = 1e9;

    // for(int i=1; i<=n; i++) cout << hor[i] << " ";
    // cout << '\n';
    // for(int i=1; i<=m; i++) cout << ver[i] << " ";

    for(int i=1; i+k-1<=n; i++) {
        for(int j=1; j+k-1<=m; j++) {
            int x = hor[i+k-1] - hor[i-1];
            int y = ver[j+k-1] - ver[j-1];
            ans = min(ans, x + y);
        }
    }

    cout << ans << '\n';
    return 0;
}