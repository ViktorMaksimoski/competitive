#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int LOG = 20;
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

int n, m;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
char mat[50][50];
bool vis[50][50];

bool ok(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c]);
}

void solve() {
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> mat[i][j];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == 'B') {
                for(int k=0; k<4; k++) {
                    int newR = i + dr[k];
                    int newC = j + dc[k];
                    if(ok(newR, newC)) {
                        if(mat[newR][newC] == '.') mat[newR][newC] = '#';
                    }
                }
            }
        }
    }

    //bfs
    queue<pair<int, int> > q;
    bool ans = true;
    if(mat[n-1][m-1] == '.') q.push({ n-1, m-1 });
    vis[n-1][m-1] = true;

    while(!q.empty()) {
        auto node = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int newR = node.first + dr[i];
            int newC = node.second + dc[i];
            if(ok(newR, newC) && mat[newR][newC] != '#') {
                vis[newR][newC] = true;
                q.push({ newR, newC });
            }
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cout << vis[i][j];
    //         if(j == m-1) cout << '\n';
    //         else cout << " ";
    //     }
    // }
    // cout << mat[n-1][m-1] << '\n';
    // cout << "-----------\n";

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == 'G' && !vis[i][j]) {
                ans = false;
                break;
            } else if(mat[i][j] == 'B' && vis[i][j]) {
                ans = false;
                break;
            }
        }
    }

    cout << (ans ? "Yes" : "No") << '\n';
}

int main() {
    setIO();

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}