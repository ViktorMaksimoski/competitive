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

int main() {
    setIO("pails");

    int x, y, k, m, ans = 1e9;
    cin >> x >> y >> k >> m;

    bool vis[101][101];
    int dist[101][101];
    memset(vis, false, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    queue<pair<int, int> > q;
    q.push({ 0, 0 });
    vis[0][0] = true;

    while(!q.empty()) {
        auto state = q.front();
        q.pop();
        
        //fill the first to the top
        if(!vis[x][state.second]) {
            if(dist[state.first][state.second] + 1 <= k) {
                dist[x][state.second] = 1 + dist[state.first][state.second];
                vis[x][state.second] = true;
                q.push({ x, state.second });
            }
        }

        //fill the second to the top
        if(!vis[state.first][y]) {
            if(dist[state.first][state.second] + 1 <= k) {
                dist[state.first][y] = 1 + dist[state.first][state.second];
                vis[state.first][y] = true;
                q.push({ state.first, y });
            }
        }

        //empty the first one
        if(!vis[0][state.second]) {
            if(dist[state.first][state.second] + 1 <= k) {
                dist[0][state.second] = 1 + dist[state.first][state.second];
                vis[0][state.second] = true;
                q.push({ 0, state.second });
            }
        }
        //empty the second one
        if(!vis[state.first][0]) {
            if(dist[state.first][state.second] + 1 <= k) {
                dist[state.first][0] = 1 + dist[state.first][state.second];
                vis[state.first][0] = true;
                q.push({ state.first, 0 });
            }
        }

        //pour the first into the second
        int newLeft, newRight;
        if(state.first + state.second > y) {
            newRight = y;
            newLeft = (state.first + state.second - y);
        } else {
            newRight = state.first + state.second;
            newLeft = 0;
        }

        if(!vis[newLeft][newRight] && dist[state.first][state.second] < k) {
            dist[newLeft][newRight] = dist[state.first][state.second] + 1;
            vis[newLeft][newRight] = true;
            q.push({ newLeft, newRight });
        }

        //pour the second into the first one
        if(state.first + state.second > x) {
            newLeft = x;
            newRight = state.first + state.second - x;
        } else {
            newLeft = state.first + state.second;
            newRight = 0;
        }

        if(!vis[newLeft][newRight] && dist[state.first][state.second] < k) {
            dist[newLeft][newRight] = dist[state.first][state.second] + 1;
            vis[newLeft][newRight] = true;
            q.push({ newLeft, newRight });
        }
    }

    for(int i=0; i<101; i++) {
        for(int j=0; j<101; j++) {
            if(vis[i][j]) {
                ans = min(ans, abs(m - (i + j)));
            }
        }
    }

    cout << ans << '\n';
    return 0;
}