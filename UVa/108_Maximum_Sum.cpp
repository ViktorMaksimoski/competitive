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

    int n;
    cin >> n;

    vector<vector<int> > mat(n+1, vector<int>(n+1));
    vector<vector<int> > prefix(n+1, vector<int>(n+1));

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> mat[i][j];

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            prefix[i][j] = mat[i][j];
            prefix[i][j] += prefix[i-1][j];
            prefix[i][j] += prefix[i][j-1];
            prefix[i][j] -= prefix[i-1][j-1];
        }
    }

    auto query = [&](int x1, int y1, int x2, int y2) {
        int ans = 0;
        ans += prefix[x2][y2];
        ans -= prefix[x1-1][y2];
        ans -= prefix[x2][y1-1];
        ans += prefix[x1-1][y1-1];
        return ans;
    };

    int ans = 0;

    for(int x1=1; x1<=n; x1++) {
        for(int y1=1; y1<=n; y1++) {
            for(int x2=x1; x2<=n; x2++) {
                for(int y2=y1; y2<=n; y2++) {
                    ans = max(ans, query(x1, y1, x2, y2));
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}