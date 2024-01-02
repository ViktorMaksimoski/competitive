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

    char mat[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> mat[i][j];

    ll ans = 0;
    int hor[n][m], ver[m][n];
    memset(hor, 0, sizeof(hor));
    memset(ver, 0, sizeof(ver));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            hor[i][j] = (mat[i][j] == 'O');
            if(j) hor[i][j] += hor[i][j-1];
        }
    }

    for(int j=0; j<m; j++) {
        for(int i=0; i<n; i++) {
            ver[j][i] = (mat[i][j] == 'I');
            if(i) ver[j][i] += ver[j][i-1];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == 'J') {
                int h = hor[i][m-1];
                if(j) h -= hor[i][j-1];
                int v = ver[j][n-1];
                if(i) v -= ver[j][i-1];
                ans += h * v;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}