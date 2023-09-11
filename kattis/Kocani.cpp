#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair
#define _USE_MATH_DEFINES

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Node = pair<ld, pair<int, int> >;

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

int diagR[4] = {1, -1, 1, -1};
int diagC[4] = {1, -1, -1, 1};

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;
    
    int mat[2*n+1][2*m+1];
    memset(mat, 0, sizeof(mat));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char x;
            cin >> x;

            if(x == 'O') {
                mat[2*i][2*j+1] = 1;
                mat[2*i+2][2*j+1] = 1;
                mat[2*i+1][2*j] = 1;
                mat[2*i+1][2*j+2] = 1;
                mat[2*i+1][2*j+1] = 2;
            }
        }
    }

    bool vis[2*n+1][2*m+1];
    memset(vis, 0, sizeof(vis));
    vector<vector<ld> > dist(2*n+1, vector<ld>(2*m+1, 1e18));
    priority_queue<Node, vector<Node>, greater<Node> > pq;

    pq.push({ 0, {0, 0} });
    dist[0][0] = 0;

    while(!pq.empty()) {
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        ld d = pq.top().first;
        pq.pop();

        if(vis[r][c]) continue;
        vis[r][c] = true;

        for(int i=0; i<4; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];
            if(newR < 0 || newR >= 2*n+1) continue; 
            if(newC < 0 || newC >= 2*m+1) continue;
            if(newR & 1 && newC & 1) continue;
            if(vis[newR][newC]) continue;

            if(dist[newR][newC] > dist[r][c] + 5) {
                dist[newR][newC] = dist[r][c] + 5;
                pq.push({ dist[r][c] + 5, {newR, newC} });
            }
        }

        if(mat[r][c]) {
            for(int i=0; i<4; i++) {
                int newR = r + diagR[i];
                int newC = c + diagC[i];
                if(newR < 0 || newR >= 2*n+1) continue; 
                if(newC < 0 || newC >= 2*m+1) continue;
                if(mat[newR][newC] != 1) continue;
                if(vis[newR][newC]) continue;
                int mr = (r + newR) / 2;
                mr = (mr / 2) * 2 + 1;
                int mc = (c + newC) / 2;
                mc = (mc / 2) * 2 + 1;
                if(mat[mr][mc] != 2) continue;


                ld newDist = dist[r][c];
                ld perimeter = ld(ld(5 * M_PI) / 2);
                newDist += perimeter;

                if(dist[newR][newC] > newDist) {
                    dist[newR][newC] = newDist;
                    pq.push({ newDist, {newR, newC} });
                }
            }
        }
    }

    cout << fixed << setprecision(10) << dist[2*n][2*m] << '\n';
    return 0;
}