#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

int main() {
    setIO();

    int n, m;
    cin >> n >> m;
    char mat[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> mat[i][j];

    bool vis[n][m];
    int dist[n][m];
    memset(dist, 0, sizeof(dist));
    memset(vis, false, sizeof(vis));

    int ans = 1;
    deque<pair<int, int> > q;
    q.push_front({0, 0});
    vis[0][0] = true;
    dist[0][0] = 1;

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop_front();

        ans = max(ans, dist[r][c]);

        for(int i=0; i<4; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];

            if(vis[newR][newC]) continue;
            if(newR < 0 || newR >= n) continue;
            if(newC < 0 || newC >= m) continue;
            if(mat[newR][newC] == '.') continue;

            if(mat[r][c] == mat[newR][newC]) {
                dist[newR][newC] = dist[r][c];
                vis[newR][newC] = true;
                q.push_front({ newR, newC });
            }

            if(mat[r][c] != mat[newR][newC]) {
                dist[newR][newC] = dist[r][c] + 1;
                vis[newR][newC] = true;
                q.push_back({ newR, newC });
            }
        }
    }

    cout << ans << '\n';
    return 0;
}