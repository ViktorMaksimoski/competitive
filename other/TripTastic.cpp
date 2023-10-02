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

int n, m, k;
vector<vector<ll> > mat, prefix;

ll query(int x1, int y1, int x2, int y2) {
    ll ans = 0;

    ans += prefix[x2][y2];
    ans -= prefix[x1-1][y2];
    ans -= prefix[x2][y1-1];
    ans += prefix[x1-1][y1-1];

    return ans;
}

bool check(int mid) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(mat[i][j] == 0) continue;
            int x1 = max(1, i - mid);
            int y1 = max(1, j - mid);
            int x2 = min(n, i + mid);
            int y2 = min(m, j + mid);
            if(query(x1, y1, x2, y2) >= k + 1)
                return true;
        }
    }

    return false;
}

void solve() {
    cin >> n >> m >> k;
    ll total = 0;
    
    mat.clear();
    prefix.clear();
    mat.resize(n+1, vector<ll>(m+1));
    prefix.resize(n+1, vector<ll>(m+1));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> mat[i][j];
            total += mat[i][j];
        }
    }

    if(total < k+1) {
        cout << -1 << '\n';
        return ;
    }

    int l=0, r=max(n, m);
    int ans = r;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            prefix[i][j] = mat[i][j];
            prefix[i][j] += prefix[i-1][j];
            prefix[i][j] += prefix[i][j-1];
            prefix[i][j] -= prefix[i-1][j-1];
        }
    }

    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << ans << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}