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

int n, k;
vector<vector<char>> mat;
vector<vector<bool>> vis;
vector<pair<int, int>> curr;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

bool ok(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < 10 && !vis[r][c]);
}

int dfs(int r, int c) {
    vis[r][c] = true;
    int sum = 1;
    curr.push_back({ r, c });

    for(int i=0; i<4; i++) {
        int newR = r + dr[i];
        int newC = c + dc[i];
        if(ok(newR, newC) && mat[r][c] == mat[newR][newC])
            sum += dfs(newR, newC);
    }

    return sum;
}

void clear() {
    for(auto &x : curr) {
        mat[x.first][x.second] = '0';
    }
}

int main() {
    setIO("mooyomooyo");

    cin >> n >> k;
    mat.resize(n, vector<char>(10, '0'));
    vis.resize(n, vector<bool>(10, false));
    for(int i=0; i<n; i++)
        for(int j=0; j<10; j++) cin >> mat[i][j];

    while(true) {
        for(int i=0; i<n; i++)
            fill(vis[i].begin(), vis[i].end(), false);
        bool ok = false;

        for(int i=0; i<n; i++) {
            for(int j=0; j<10; j++) {
                if(mat[i][j] != '0' && !vis[i][j]) {
                    if(dfs(i, j) >= k) {
                        ok = true;
                        clear();
                    }
                    curr.clear();
                }
            }
        }

        for(int j=0; j<10; j++) {
            vector<char> gravity;
            for(int i=n-1; i>=0; i--) {
                if(mat[i][j] != '0') gravity.push_back(mat[i][j]);
            }

            for(int i=n-1; i>=0; i--) {
                if(n-1-i < gravity.size()) mat[i][j] = gravity[n-1-i];
                else mat[i][j] = '0';
            }
        }

        if(!ok) break;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<10; j++) {
            cout << mat[i][j];
            if(j == 9) cout << '\n';
        }
    }
    return 0;
}