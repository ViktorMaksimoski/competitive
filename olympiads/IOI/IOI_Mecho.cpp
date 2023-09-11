#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cstring>

#define pb push_back
#define sz(x) (int)x.size()
#define mp make_pair

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n, s;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
char mat[800][800];
vector<pii> hives;
pii mecho, home;

int dist[800][800][2];
bool vis[800][800];

bool ok(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n && !vis[r][c] && mat[r][c] != 'T');
}

void hive_fill() {
    queue<pair<int, int> > q;
    for(pii &x : hives) {
        q.push(x);
        vis[x.first][x.second] = true;
    }

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];
            if(!ok(newR, newC) || mat[newR][newC] == 'D') continue;
            vis[newR][newC] = true;
            dist[newR][newC][1] = dist[r][c][1] + 1;
            q.push({ newR, newC });
        }
    }
}

int calcMinutes(int steps) {
    return steps / s;
}

bool check(int mid) {
    queue<pii> q;
    memset(vis, 0, sizeof(vis));

    q.push(mecho);
    vis[mecho.first][mecho.second] = true;
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if(r == home.first && c == home.second)
            return true;

        for(int i=0; i<4; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];
            if(!ok(newR, newC)) continue;
            if(mid >= dist[newR][newC][1] && mat[newR][newC] != 'D') 
                continue;
            if(mid + calcMinutes(dist[r][c][0] + 1) >= dist[newR][newC][1] && mat[newR][newC] != 'D')
                continue;
            q.push({ newR, newC });
            vis[newR][newC] = true;
            dist[newR][newC][0] = dist[r][c][0] + 1;
        }
    }

    return false;
}

int32_t main() {
    setIO();

    cin >> n >> s;
    memset(dist, 0, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == 'H') hives.pb({i, j});
            else if(mat[i][j] == 'M') mecho = {i, j};
            else if(mat[i][j] == 'D') home = {i, j};
        }
    }

    hive_fill();

    int ans = -1;
    int l=0, r=dist[mecho.first][mecho.second][1]-1;
    while(l <= r) {
        int mid = (l + r) / 2;

        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}