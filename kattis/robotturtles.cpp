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

//dole, levo, gore, desno
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};

using Node = pair<array<int, 4>, string>;

int32_t main() {
    setIO();

    char mat[8][8];
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            cin >> mat[i][j];

    string ans = "";
    for(int i=0; i<2000; i++) ans += ".";

    vector<vector<vector<int>> > dist(8, vector<vector<int>>(8, vector<int>(4, 1e9)));
    vector<vector<vector<bool>> > vis(8, vector<vector<bool>>(8, vector<bool>(4, 0)));
    priority_queue<Node, vector<Node>, greater<Node> > pq;

    dist[7][0][3] = 0;
    pq.push({ {0, 7, 0, 3}, "" });

    while(!pq.empty()) {
        int r = pq.top().first.at(1);
        int c = pq.top().first.at(2);
        int dir = pq.top().first.at(3);
        string moves = pq.top().second;
        pq.pop();

        if(vis[r][c][dir]) continue;
        vis[r][c][dir] = true;

        // cout << "(" << r << ", " << c << "), " << dir << '\n';
        // cout << dist[r][c][dir] << " " << moves << '\n';

        if(mat[r][c] == 'D' && sz(moves) < sz(ans))
            ans = moves;

        //rotate left;
        int leftDir = (dir == 0 ? 3 : dir - 1);
        if(dist[r][c][leftDir] > dist[r][c][dir] + 1) {
            dist[r][c][leftDir] = dist[r][c][dir] + 1;
            string leftMoves = moves;
            leftMoves += 'L';
            pq.push({ {dist[r][c][leftDir], r, c, leftDir}, leftMoves });
        }

        int rightDir = (dir == 3 ? 0 : dir + 1);
        if(dist[r][c][rightDir] > dist[r][c][dir] + 1) {
            dist[r][c][rightDir] = dist[r][c][dir] + 1;
            string rightMoves = moves;
            rightMoves += 'R';
            pq.push({ {dist[r][c][rightDir], r, c, rightDir}, rightMoves });
        }

        int newR = r + dr[dir];
        int newC = c + dc[dir];
        if(newR < 0 || newR == 8) continue;
        if(newC < 0 || newC == 8) continue;
        if(mat[newR][newC] == 'C') continue;

        if(dist[newR][newC][dir] > dist[r][c][dir] + 1 + (mat[newR][newC] == 'I')) {
            dist[newR][newC][dir] = dist[r][c][dir] + 1 + (mat[newR][newC] == 'I');
            string newMoves = moves;
            if(mat[newR][newC] == 'I') newMoves += 'X';
            newMoves += 'F';
            pq.push({ {dist[newR][newC][dir], newR, newC, dir}, newMoves });
        }
    }

    if(ans[0] == '.') cout << "no solution\n";
    else cout << ans << '\n';
    return 0;
}