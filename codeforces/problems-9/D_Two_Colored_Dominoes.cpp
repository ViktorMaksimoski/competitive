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

void solve() {
    int n, m;
    cin >> n >> m;

    char mat[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> mat[i][j];

    vector<int> r(n, 0), c(m, 0);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == 'U') {
                if(!r[i]) mat[i][j] = 'W', mat[i+1][j] = 'B';
                else mat[i][j] = 'B', mat[i+1][j] = 'W';
                r[i] ^= 1;
            } else if(mat[i][j] == 'L') {
                if(!c[j]) mat[i][j] = 'W', mat[i][j+1] = 'B';
                else mat[i][j] = 'B', mat[i][j+1] = 'W';
                c[j] ^= 1;
            }
        }
    }

    for(int i=0; i<n; i++) {
        int b=0, w=0;

        for(int j=0; j<m; j++) {
            if(mat[i][j] == 'B') b++;
            if(mat[i][j] == 'W') w++;
        }

        if(b != w) {
            cout << -1 << '\n';
            return ;
        }
    }

    for(int j=0; j<m; j++) {
        int b=0, w=0;

        for(int i=0; i<n; i++) {
            if(mat[i][j] == 'B') b++;
            if(mat[i][j] == 'W') w++;
        }

        if(b != w) {
            cout << -1 << '\n';
            return ;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cout << mat[i][j];
        cout << '\n';
    }
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}