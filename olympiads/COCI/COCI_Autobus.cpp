#include <bits/stdc++.h>
 
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Node = array<ll, 3>;
 
const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
 
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
 
int32_t main() {
    setIO();
 
    int n, m;
    cin >> n >> m;
    vector<vector<pii> > graph(n+1);
    int mat[n+1][n+1];
    memset(mat, 0, sizeof(mat));
    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        if(mat[a][b] == 0) mat[a][b] = w;
        else mat[a][b] = min(mat[a][b], w);
    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(mat[i][j] != 0)
                graph[i].pb({ j, mat[i][j] });
 
    int k, q;
    cin >> k >> q;
    k = min(k, n);
    vector<vector<ll> > ans(n+1, vector<ll>(n+1, 1e18));
    vector<vector<vector<ll> > > dist(n+1, vector<vector<ll>>(n+1, vector<ll>(k+1, 1e18)));
    priority_queue<Node, vector<Node>, greater<Node> > pq;

    for(int i=1; i<=n; i++) {
        dist[i][i][0] = 0;
        bool vis[n+1][k+1];
        memset(vis, 0, sizeof(vis));
        pq.push({ 0, 0, i });

        while(!pq.empty()) {
            ll d = pq.top().at(0);
            int c = pq.top().at(1);
            int u = pq.top().at(2);
            pq.pop();

            if(vis[u][c]) continue;
            vis[u][c] = true;

            if(c == k) continue;
            for(pii &v : graph[u]) {
                if(dist[i][v.first][c+1] > dist[i][u][c] + v.second) {
                    dist[i][v.first][c+1] = dist[i][u][c] + v.second;
                    if(vis[v.first][c+1]) continue;
                    pq.push({ dist[i][v.first][c+1], c+1, v.first });
                }
            }
        }

        for(int j=1; j<=n; j++) {
            for(int x=0; x<k+1; x++) {
                ans[i][j] = min(ans[i][j], dist[i][j][x]);
            }
        }
    }

    
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << (ans[a][b] == 1e18 ? -1 : ans[a][b]) << '\n';
    }
    return 0;
}