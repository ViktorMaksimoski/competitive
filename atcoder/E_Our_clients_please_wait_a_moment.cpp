#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Node = array<ll, 3>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    setIO();

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int d[n+1][n+1];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) cin >> d[i][j];

    bool vis[n+1][2];
    vector<vector<ll> > dist(n+1, vector<ll>(2, 1e18));
    memset(vis, 0, sizeof(vis));
    priority_queue<Node, vector<Node>, greater<Node> > pq;

    pq.push({ 0, 0, 1});
    dist[1][0] = 0;
    
    while(!pq.empty()) {
        int u = pq.top().at(2);
        int t = pq.top().at(1);
        pq.pop();

        if(vis[u][t]) continue;
        vis[u][t] = 1;

        for(int v=1; v<=n; v++) {
            if(t == 0) {
                if(dist[v][t] > dist[u][t] + d[u][v] * a) {
                    dist[v][t] = dist[u][t] + d[u][v] * a;
                    pq.push({ dist[v][t], t, v });
                }

                if(dist[v][1] > dist[u][t] + d[u][v] * b + c) {
                    dist[v][1] = dist[u][t] + d[u][v] * b + c;
                    pq.push({ dist[v][1], 1, v });
                }
            } else {
                if(dist[v][1] > dist[u][t] + d[u][v] * b + c) {
                    dist[v][1] = dist[u][t] + d[u][v] * b + c;
                    pq.push({ dist[v][1], 1, v });
                }
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]) << '\n';
    return 0;
}