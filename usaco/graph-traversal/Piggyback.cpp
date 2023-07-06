#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

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
    setIO("piggyback");

    int b, e, p, n, m;
    cin >> b >> e >> p >> n >> m;
    vector<vector<int> > graph(n+1);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //0 - bessie, 1 - elsie
    vector<vector<int> > dist(3, vector<int>(n+1, 0));
    vector<vector<bool> > vis(3, vector<bool>(n+1, 0));

    queue<int> q[3];

    q[0].push(1);
    q[1].push(2);
    q[2].push(n);
    dist[0][1] = 0;
    dist[1][2] = 0;
    dist[2][n] = 0;
    vis[2][n] = true;
    vis[0][1] = true;
    vis[1][2] = true;

    auto bfs = [&](int cow) {
        while(!q[cow].empty()) {
            int u = q[cow].front();
            q[cow].pop();

            for(int &v : graph[u]) {
                if(vis[cow][v]) continue;
                vis[cow][v] = true;
                dist[cow][v] = dist[cow][u];
                if(cow == 0) dist[cow][v] += b;
                if(cow == 1) dist[cow][v] += e;
                if(cow == 2) dist[cow][v] += 1;
                q[cow].push(v);
            }
        }
    };

    for(int i=0; i<3; i++) bfs(i);

    int ans = 1e9;

    for(int i=1; i<=n; i++) {
        int bessie = dist[0][i];
        int elsie = dist[1][i];
        int both = dist[2][i] * p;
        ans = min(ans, bessie + elsie + both);
        //cout << i << " -> " << bessie + elsie + both << '\n';
    }

    cout << ans << '\n';
    return 0;
}