#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define int long long

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

//meet in the middle
//idea:
// try (n + m - 2) / 2 moves from (0, 0)
// try remaining moves from (n-1, m-1)
// combine results for left and right :)
int32_t main() {
    setIO();

    int n, m;
    ll k;
    cin >> n >> m >> k;

    ll mat[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> mat[i][j];

    if(n == 1 && m == 1) {
        cout << (mat[0][0] == k) << '\n';
        return 0;
    }

    vector<vector<map<int, int> >> leftOcc(n, vector<map<int, int> >(m));

    //MITM for left side
    int total = n + m - 2;
    int leftMoves = total / 2;
    int rightMoves = total - leftMoves;
    ll ans = 0;

    leftOcc[0][0][mat[0][0]]++;
    
    for(int x=1; x<=leftMoves; x++) {
        for(int s=0; s<(1<<x); s++) {
            ll curr = mat[0][0];
            bool ok = true;
            int r=0, c=0;

            for(int i=0; i<x; i++) {
                if(s & (1 << i)) {
                    r++;
                    if(r >= n) { ok = false; break; }
                    curr ^= mat[r][c];
                } else {
                    c++;
                    if(c >= m) { ok = false; break; }
                    curr ^= mat[r][c];
                }
            }

            if(ok) leftOcc[r][c][curr]++;
        }
    }

    for(int x=1; x<=rightMoves; x++) {
        for(int s=0; s<(1<<x); s++) {
            int r=n-1, c=m-1;
            bool ok = true;
            ll curr = mat[n-1][m-1];

            for(int i=0; i<x; i++) {
                if(s & (1 << i)) {
                    r--;
                    if(r < 0) { ok = false; break; }
                    curr ^= mat[r][c];
                } else {
                    c--;
                    if(c < 0) { ok = false; break; }
                    curr ^= mat[r][c];
                }
            }

            if(ok) {
                ans += leftOcc[r][c][k^curr^mat[r][c]];
            }
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         if(leftOcc[i][j].size() == 0) continue;
    //         cout << "(" << i+1 << ", " << j+1 << ")\n";
    //         for(auto &x : leftOcc[i][j]) {
    //             cout << "occ(" << x.first << "): " << x.second << '\n';
    //         }
    //     }
    // }

    cout << ans << '\n';
    return 0;
}