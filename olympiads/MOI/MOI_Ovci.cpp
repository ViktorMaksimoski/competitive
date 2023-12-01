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

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;

    char mat[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> mat[i][j];

    bool vis[n][m];
    memset(vis, 0, sizeof(vis));

    int ans1 = 0, ans2 = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == '#') continue;
            if(vis[i][j]) continue;
            queue<pii> q;
            q.push({ i, j });
            vis[i][j] = 1;
            int cnt1 = 0, cnt2 = 0;

            while(!q.empty()) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                if(mat[r][c] == 'o') cnt1++;
                if(mat[r][c] == 'v') cnt2++;

                for(int i=0; i<4; i++) {
                    int newR = r + dr[i];
                    int newC = c + dc[i];
                    if(newR < 0 || newR >= n) continue;
                    if(newC < 0 || newC >= m) continue;
                    if(vis[newR][newC]) continue;
                    if(mat[newR][newC] == '#') continue;
                    vis[newR][newC] = 1;
                    q.push({ newR, newC });
                }
            }

            if(cnt1 > cnt2) ans1 += cnt1;
            else ans2 += cnt2;
        }
    }

    cout << ans1 << " " << ans2 << '\n';
    return 0;
}