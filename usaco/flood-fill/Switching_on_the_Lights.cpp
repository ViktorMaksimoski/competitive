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

map<pair<int, int>, vector<pair<int, int>> > toggles;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
bool light[100][100];
bool vis[100][100];
int n, m, ans = 0;

bool ok(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

void dfs(int r, int c){
   vis[r][c] = true;

   for(auto &room : toggles[{r, c}]) {
    light[room.first][room.second] = true;

    for(int i=0; i<4; i++) {
        int newR = room.first + dr[i];
        int newC = room.second + dc[i];
        if(ok(newR, newC) && vis[newR][newC] && !vis[room.first][room.second])
            dfs(room.first, room.second);
    }
   }

   for(int i=0; i<4; i++) {
    int newR = r + dr[i];
    int newC = c + dc[i];
    if(ok(newR, newC) && !vis[newR][newC] && light[newR][newC])
        dfs(newR, newC);
   }
} 

int main() {
    setIO("lightson");

    cin >> n >> m; 
    
    memset(vis, false, sizeof(vis));
    memset(light, false, sizeof(light));
    for(int i=0; i<m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        toggles[make_pair(a, b)].push_back({ c, d });
    }
    

    light[0][0] = true;
    dfs(0, 0);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            ans += light[i][j];

    cout << ans << '\n';
    return 0;
}