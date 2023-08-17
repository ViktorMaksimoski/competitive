#include <bits/stdc++.h>
#define pb push_back
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;
 
int n, m;
pii r, e;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
char mat[1000][1000];
bool vis[2][1000][1000];
int dist[2][1000][1000];
vector<pii> bad;
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> m;
    queue<pii> q;
 
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == 'Z') e = { i, j };
            if(mat[i][j] == 'R') r = { i, j };
            if(mat[i][j] == 'G') q.push({ i, j }), bad.pb({ i, j });
        }
    }
 
    auto bfs = [&](int t, int mx) {
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                vis[t][i][j] = false, dist[t][i][j] = -1;
 
        if(t == 0) {
            for(pii &b : bad) {
                vis[t][b.first][b.second] = true;
                dist[t][b.first][b.second] = 0;
            }
        } else {
            vis[t][r.first][r.second] = true;
            dist[t][r.first][r.second] = 0;
        }
 
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
 
            for(int i=0; i<4; i++) {
                int newR = r + dr[i];
                int newC = c + dc[i];
                if(newR < 0 || newR >= n) continue;
                if(newC < 0 || newC >= m) continue;
                if(vis[t][newR][newC]) continue;
                if(mat[newR][newC] == '*') continue;
                if(t && dist[0][newR][newC] < mx) continue;
 
                q.push({ newR, newC });
                vis[t][newR][newC] = true;
                dist[t][newR][newC] = dist[t][r][c] + 1;
            }
        }
    };
 
    //BFS od zatvorenici
    bfs(0, 0);
 
    int ans = 0;
    int lp=1, rp=n*m;
    while(lp <= rp) {
        int mid = (lp + rp) / 2;
        if(dist[0][r.first][r.second] >= mid) q.push(r);
        bfs(1, mid);
 
        if(vis[1][e.first][e.second]) {
            lp = mid + 1;
            ans = mid;
        } else rp = mid - 1;
    }
 
    cout << ans << '\n';
    return 0;
}