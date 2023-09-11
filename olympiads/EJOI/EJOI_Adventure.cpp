#include <bits/stdc++.h>

using namespace std;
using Node = array<int, 3>;

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

int getCost(int curr, int target) {
    int arr[4] = {1, 2, 3, 0};
    int ans = 0;

    int currPos = -1;
    for(int i=0; i<4; i++) {
        if(arr[i] == curr) {
            currPos = i;
            break;
        }
    }

    while(arr[(currPos + ans) % 4] != target) ans++;

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int mat[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char ch;
            cin >> ch;
            if(ch == 'X') mat[i][j] = -1;
            if(ch == 'E') mat[i][j] = 2;
            if(ch == 'W') mat[i][j] = 0;
            if(ch == 'N') mat[i][j] = 1;
            if(ch == 'S') mat[i][j] = 3;
        }
    }

    bool vis[n][m];
    vector<vector<int> > dist(n, vector<int>(m, 1e9));
    memset(vis, 0, sizeof(vis));

    dist[0][0] = 0;
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    pq.push({ 0, 0, 0 });

    while(!pq.empty()) {
        int r = pq.top().at(1);
        int c = pq.top().at(2);
        pq.pop();

        if(vis[r][c]) continue;
        vis[r][c] = true;
        if(mat[r][c] == -1) continue;

        for(int i=0; i<4; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];
            if(newR < 0 || newR >= n) continue;
            if(newC < 0 || newC >= m) continue;
            
            int newDist = dist[r][c] + getCost(mat[r][c], i);

            if(dist[newR][newC] > newDist) {
                dist[newR][newC] = newDist;
                pq.push({ dist[newR][newC], newR, newC });
            }
        }
    }

    if(!vis[n-1][m-1]) cout << -1 << '\n';
    else cout << dist[n-1][m-1] << '\n';
    return 0;
}