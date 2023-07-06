#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;
 
void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}
 
void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    if(name != "") setUSA(name);
}
 
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
 
int main() {
    setIO();
 
    int n, m;
    cin >> n >> m;
    vector<vector<char> > mat(n, vector<char>(m));
    vector<pii> monsters;
    pii start;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == 'A') start = {i, j};
            if(mat[i][j] == 'M') monsters.push_back({ i, j });
        }
    }

    if(n*m == 1) {
        cout << "YES\n0\n";
        return 0;
    }

    if(start.first == 0 || start.first == n-1 
    || start.second == 0 || start.second == m-1) {
        cout << "YES\n0\n";
        return 0;
    }

    vector<vector<vector<bool>> > vis(2, vector<vector<bool>>(n, vector<bool>(m, false)));
    vector<vector<vector<int>> > dist(2, vector<vector<int>>(n, vector<int>(m, 1e9)));

    queue<pii> q;
    for(pii &mon : monsters)
        q.push(mon), dist[0][mon.first][mon.second] = 0, vis[0][mon.first][mon.second] = 1;

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= n) continue;
            if(nc < 0 || nc >= m) continue;
            if(vis[0][nr][nc]) continue;
            if(mat[nr][nc] == '#') continue;

            dist[0][nr][nc] = min(dist[0][nr][nc], dist[0][r][c] + 1);
            vis[0][nr][nc] = true;
            q.push({ nr, nc });
        }
    }

    vector<vector<char> > par(n, vector<char>(m, ' '));
    q.push(start);
    vis[1][start.first][start.second] = true;
    dist[1][start.first][start.second] = 0;
    par[start.first][start.second] = 'X';

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= n) continue;
            if(nc < 0 || nc >= m) continue;
            if(vis[1][nr][nc]) continue;
            if(mat[nr][nc] == '#') continue;
            if(dist[0][nr][nc] <= dist[1][r][c] + 1) continue;

            if(i == 0) par[nr][nc] = 'L';
            if(i == 1) par[nr][nc] = 'U';
            if(i == 2) par[nr][nc] = 'R';
            if(i == 3) par[nr][nc] = 'D';

            vis[1][nr][nc] = true;
            dist[1][nr][nc] = dist[1][r][c] + 1;
            q.push({ nr, nc });
        }
    }

    auto trace = [&](int r, int c) {
        vector<char> ans;

        while(par[r][c] != 'X') {
            ans.push_back(par[r][c]);
            if(par[r][c] == 'L') c++;
            else if(par[r][c] == 'R') c--;
            else if(par[r][c] == 'U') r++;
            else r--;
        }
        
        reverse(all(ans));
        for(char &ch : ans) cout << ch;
    };

    for(int i=0; i<n; i++) {
        if(vis[1][i][0]) {
            cout << "YES\n";
            cout << dist[1][i][0] << '\n';
            trace(i, 0);
            return 0;
        }

        if(vis[1][i][m-1]) {
            cout << "YES\n";
            cout << dist[1][i][m-1] << '\n';
            trace(i, m-1);
            return 0;
        }
    }

    for(int i=0; i<m; i++) {
        if(vis[1][0][i]) {
            cout << "YES\n";
            cout << dist[1][0][i] << '\n';
            trace(0, i);
            return 0;
        }

        if(vis[1][n-1][i]) {
            cout << "YES\n";
            cout << dist[1][n-1][i] << '\n';
            trace(n-1, i);
            return 0;
        }
    }

    
    cout << "NO\n";
    return 0;
}