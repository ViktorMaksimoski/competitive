#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()

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

int dr[8] = {0, -1, 0, 1, 1, 1, -1, -1};
int dc[8] = {-1, 0, 1, 0, -1, 1, -1, 1};

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;
    char mat[n][m];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> mat[i][j];

    int ans = 0;
    bool vis[n][m];
    memset(vis, 0, sizeof(vis));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(vis[i][j]) continue;
            if(mat[i][j] == '*') continue;
            ans++;

            queue<pii> q;
            vis[i][j] = true;
            q.push({i, j});
            while(!q.empty()) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i=0; i<8; i++) {
                    int newR = r + dr[i];
                    int newC = c + dc[i];
                    if(newR < 0 || newR >= n) continue;
                    if(newC < 0 || newC >= m) continue;
                    if(vis[newR][newC]) continue;
                    if(mat[newR][newC] == '*') continue;

                    q.push({newR, newC});
                    vis[newR][newC] = true;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}