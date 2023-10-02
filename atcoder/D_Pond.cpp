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

int n, k;
int mat[801][801];
int prefix[801][801];

int query(int x1, int y1, int x2, int y2) {
    int ans = 0;

    ans += prefix[x2][y2];
    ans -= prefix[x1-1][y2];
    ans -= prefix[x2][y1-1];
    ans += prefix[x1-1][y1-1];

    return ans;
}

bool check(int median) {
    memset(prefix, 0, sizeof(prefix));
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            prefix[i][j] = (mat[i][j] <= median);
            prefix[i][j] += prefix[i-1][j];
            prefix[i][j] += prefix[i][j-1];
            prefix[i][j] -= prefix[i-1][j-1];
        }
    }

    for(int i=1; i+k-1<=n; i++)
        for(int j=1; j+k-1<=n; j++)
            if(query(i, j, i+k-1, j+k-1) * 2 >= k*k) 
                return true;

    return false;
}

int32_t main() {
    setIO();

    cin >> n >> k;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) cin >> mat[i][j];

    int ans = 1e9;
    int l=0, r=1e9;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}