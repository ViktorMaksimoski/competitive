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

int n;
int mat[16][16];
ll dp[1<<16];

ll f(int mask) {
    if(dp[mask] != -1) return dp[mask];
    ll ans = 0;

    for(int i=0; i<n; i++) {
        if(mask & (1 << i)) continue;
        for(int j=i+1; j<n; j++) {
            if(mask & (1 << j)) continue;
            int newMask = mask;
            newMask |= (1 << i);
            newMask |= (1 << j);
            ans = max(ans, mat[i][j] + f(newMask));
        }
    }

    return dp[mask] = ans;
}

int32_t main() {
    setIO();

    cin >> n;
    memset(mat, 0, sizeof(mat));
    memset(dp, -1, sizeof(dp));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            int x;
            cin >> x;
            mat[i][i+j+1] = x;
            mat[i+j+1][i] = x;
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         cout << mat[i][j] << " ";
    //         if(j == n-1) cout << '\n';
    //     }
    // }

    cout << f(0) << '\n';
    return 0;
}