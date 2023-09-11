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
using Node = array<int, 3>;
 
const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;
 
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
 
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
 
int32_t main() {
    setIO();
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<char> > mat(n, vector<char>(m));
    map<pii, int> mp;
    int s;
    int b;
    int curr = 1;
    int total = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] != '.' && mat[i][j] != '#') {
                mp[{i, j}] = curr;
                if(mat[i][j] == 'S') s = curr;
                if(mat[i][j] == 'B') b = curr;
                curr++;
                total++;
            }
        }
    }
 
    curr = 1;
    vector<vector<pii> > graph(total+1);
 
    auto bfs = [&](int x, int y, int id) {
        bool vis[n][m];
        memset(vis, 0, sizeof(vis));
        int dist[n][m];
        memset(dist, 0, sizeof(dist));
        queue<pii> q;
 
        q.push({ x, y });
        vis[x][y] = 1;
 
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
 
            if(mat[r][c] != '.' && mat[r][c] != '#' && dist[r][c] > 0) {
                graph[id].push_back({ mp[{r, c}], dist[r][c] });
            }
 
            for(int i=0; i<4; i++) {
                int newR = r + dr[i];
                int newC = c + dc[i];
                if(newR < 0 || newR >= n) continue;
                if(newC < 0 || newC >= m) continue;
                if(vis[newR][newC]) continue;
                if(mat[newR][newC] == '#') continue;
 
                vis[newR][newC] = true;
                q.push({ newR, newC });
                dist[newR][newC] = dist[r][c] + 1;
            }
        }
    };
 
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
             if(mat[i][j] != '.' && mat[i][j] != '#')
                bfs(i, j, curr++);
        }
    }
 
    //subtask 1
    if(total == 3) {
        int sd = 0;
        for(auto &x : graph[s]) {
            if(x.first != b) sd = x.second;
        }

        int bd = 0;
        for(auto &x : graph[b]) {
            if(x.first != s) bd = x.second;
        }

        if(sd == 0 || bd == 0) {
            cout << -1 << '\n';
            return 9;
        }

        cout << sd + bd << '\n';
        return 0;
    }
 
    //subtask 2
    if(total == 4) {
        int ans = 1e9;

        vector<int> v;
        v.push_back(s);
        for(int i=1; i<=4; i++) {
            if(i != b && i != s) v.push_back(i);
        }
        v.push_back(b);

        //first check
        int sd = 0;
        for(auto &x : graph[v[0]])
            if(x.first == v[1]) sd = x.second;
        int dd = 0;
        for(auto &x : graph[v[1]])
            if(x.first == v[2]) dd = x.second;
        int db = 0;
        for(auto &x : graph[v[2]])
            if(x.first == v[3]) db = x.second;
        if(sd && dd && db) ans = min(ans, sd + dd + db);

        sd = 0, dd = 0, db = 0;
        swap(v[1], v[2]);
        for(auto &x : graph[v[0]])
            if(x.first == v[1]) sd = x.second;
        for(auto &x : graph[v[1]])
            if(x.first == v[2]) dd = x.second;
        for(auto &x : graph[v[2]])
            if(x.first == v[3]) db = x.second;

        if(sd && dd && db) ans = min(ans, sd + dd + db);
        cout << (ans == 1e9 ? -1 : ans) << '\n';
        return 0;
    }

    int ans = 1e9;
    vector<vector<int> > dp(total, vector<int>(1<<total, 1e9));
    dp[s-1][1<<(s-1)] = 0;

    for(int mask=1; mask<(1<<total); mask++) {
        for(int i=0; i<total; i++) {
            if((mask & (1 << (s-1))) == 0) continue;
            if((mask & (1 << i)) == 0) continue;

            for(pii &next : graph[i+1]) {
                int v = next.first-1;
                int w = next.second;
                if(i == v) continue;

                if(mask & (1 << v)) {
                    dp[i][mask] = min(dp[i][mask], dp[v][mask^(1<<i)] + w);
                }
            }

            if(mask == (1<<total) - 1 && i == b-1)
                ans = min(ans, dp[i][mask]);

        }
    }

    cout << (ans == 1e9 ? -1 : ans) << '\n';
    return 0;
}