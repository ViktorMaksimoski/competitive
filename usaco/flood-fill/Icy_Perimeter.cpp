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

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
int n;
vector<vector<char> > mat;
vector<vector<bool> > vis;
int currA=0, currP=0;

void dfs(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= n || mat[i][j] == '.') {
        currP++;
        return ;
    } else if(vis[i][j]) {
        return ;
    }

    currA += (mat[i][j] == '#');
    vis[i][j] = true;

    for(int k=0; k<4; k++)
        dfs(i + dr[k], j + dc[k]);
}

int main() {
    setIO("perimeter");

    cin >> n; 
    int area = 0, per = 1e9;
    mat.resize(n, vector<char>(n));
    vis.resize(n, vector<bool>(n, false));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin >> mat[i][j];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(vis[i][j] && mat[i][j] == '#') continue;
            if(mat[i][j] == '.') continue;
            dfs(i, j);

            if(currA > area) {
                area = currA;
                per = currP;
            } else if(currA == area) {
                per = min(per, currP);
            }

            currA = 0;
            currP = 0;
        }
    }

    
    cout << area << " " << per << '\n';
    return 0;
}