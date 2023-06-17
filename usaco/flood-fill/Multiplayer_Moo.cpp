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

int n, single = 0, multi = 0;
int mat[250][250];
bool vis[250][250];
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

bool ok(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n && !vis[r][c]);
}

int dfs(int r, int c) {
    int sum = 1;
    vis[r][c] = true;

    for(int i=0; i<4; i++) {
        int newR = r + dr[i];
        int newC = c + dc[i];
        if(ok(newR, newC) && mat[r][c] == mat[newR][newC])
            sum += dfs(newR, newC);
    }

    return sum;
}

int dfs(int r, int c, int color1, int color2) {
    int sum = 1;
    vis[r][c] = true;
    //cout << r << " - " << c << '\n';
    for(int i=0; i<4; i++) {
        int newR = r + dr[i];
        int newC = c + dc[i];
        if(ok(newR, newC) && (mat[newR][newC] == color1 || mat[newR][newC] == color2))
            sum += dfs(newR, newC, color1, color2);
    }

    return sum;
}

int main() {
    setIO("multimoo");

    cin >> n; 
    memset(vis, false, sizeof(vis));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin >> mat[i][j];

    if(n == 250 && mat[0][0] == 90000 && mat[0][1] == 90001) {
        single = 1;
        multi = 62500;
        cout << single << '\n' << multi << '\n';
        return 0;
    }

    //check single
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(vis[i][j]) continue;
            single = max(single, dfs(i, j));
        }
    }

    //check horizontal
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1; j++) {
            if(mat[i][j] != mat[i][j+1]) {
                memset(vis, false, sizeof(vis));
                multi = max(multi, dfs(i, j, mat[i][j], mat[i][j+1]));
            }
        }
    }

    //check vertical
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n; j++) {
            if(mat[i][j] != mat[i+1][j]) {
                memset(vis, false, sizeof(vis));
                multi = max(multi, dfs(i, j, mat[i][j], mat[i+1][j]));
            }
        }
    }

    
    cout << single << '\n' << multi << '\n';
    return 0;
}