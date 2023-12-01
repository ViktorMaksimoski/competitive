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

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

inline int bits(int x) {
    return __builtin_popcount(x);
}

vector<vector<int> > best;
vector<int> totalLeaks;
int dp[301][3001];
int n, k, m;

int f(int pos, int left) {
    if(pos == n) return 0;
    if(dp[pos][left] != -1) return dp[pos][left];

    int ans = 0;

    for(int i=0; i<=min(totalLeaks[pos], left); i++) {
        ans = max(ans, best[pos][i] + f(pos+1, left-i));
    }

    return dp[pos][left] = ans;
}

int32_t main() {
    setIO();
    memset(dp, -1, sizeof(dp));

    cin >> n >> k >> m;

    best.resize(n, vector<int>(k+1));
    totalLeaks.resize(n);

    for(int it=0; it<n; it++) {
        char mat[m][m];
        bool vis[m][m];
        vector<pii> leaks;

        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                cin >> mat[i][j];
                if(mat[i][j] == 'L')
                    leaks.push_back({ i, j });
            }
        }

        for(int s=0; s<(1<<sz(leaks)); s++) {
            if(sz(leaks) - bits(s) > k) continue;
            memset(vis, 0, sizeof(vis));
            int res = m*m;

            queue<pii> q;

            for(int i=0; i<sz(leaks); i++) {
                if(s & (1 << i)) {
                    q.push(leaks[i]);
                    vis[leaks[i].first][leaks[i].second] = 1;
                }
            }

            while(!q.empty()) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                res--;

                for(int i=0; i<4; i++) {
                    int newR = r + dr[i];
                    int newC = c + dc[i];

                    if(newR < 0 || newR >= m) continue;
                    if(newC < 0 || newC >= m) continue;
                    if(vis[newR][newC]) continue;
                    if(mat[newR][newC] == 'L') continue;
                    if(mat[newR][newC] > mat[r][c]) continue;

                    vis[newR][newC] = 1;
                    q.push({ newR, newC });
                }
            }

            totalLeaks[it] = sz(leaks);
            best[it][sz(leaks)-bits(s)] = max(best[it][sz(leaks)-bits(s)], res);
        }
    }

    cout << f(0, k) << '\n';
    return 0;
}