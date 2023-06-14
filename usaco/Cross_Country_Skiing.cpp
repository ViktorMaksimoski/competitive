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

int mat[500][500];
bool vis[500][500];
int n, m;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

bool ok(int r, int c) {
     return (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c]);
}

void dfs(int r, int c, int h) {
     vis[r][c] = true;

     for(int i=0; i<4; i++) {
          int newR = r + dr[i];
          int newC = c + dc[i];
          if(ok(newR, newC) && abs(mat[r][c] - mat[newR][newC]) <= h) 
               dfs(newR, newC, h);
     }
}

bool check(int diff, vector<pair<int, int> > &endpoints) {
     memset(vis, false, sizeof(vis));
     dfs(endpoints[0].first, endpoints[0].second, diff);

     for(pair<int, int> &p : endpoints)
          if(!vis[p.first][p.second]) return false;

     return true;
}

int main() {
    setIO("ccski");

    cin >> n >> m;
    int mx=0, ans = 0;
    vector<pair<int, int> > endpoints;
    for(int i=0; i<n; i++) {
     for(int j=0; j<m; j++) {
          cin >> mat[i][j];
          mx = max(mx, mat[i][j]);
     }
    }

    for(int i=0; i<n; i++) {
     for(int j=0; j<m; j++) {
          int x;
          cin >> x;
          if(x) endpoints.push_back({ i, j });
     }
    }

    int l=0, r=mx;
    while(l <= r) {
     auto mid = l + (r - l) / 2;
     //cout << mid << '\n';
     if(check(mid, endpoints)) {
          ans = mid;
          r = mid - 1;
     } else {
          l = mid + 1;
     }
    }
    
    cout << ans << '\n';
    return 0;
}