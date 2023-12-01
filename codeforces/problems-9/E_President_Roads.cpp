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

const int mod = 2e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct Edge { int a, b, w; };

int32_t main() {
    setIO();

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<vector<pii> > > graph(2, vector<vector<pii>>(n+1));
    vector<Edge> edges(m);

    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[0][a].push_back({ b, w });
        graph[1][b].push_back({ a, w });
        edges[i] = Edge{a, b, w};
    }

    vector<vector<ll> > dist(2, vector<ll>(n+1, 1e18));
    vector<vector<ll> > ways(2, vector<ll>(n+1, 0));

    auto dijkstra = [&](int start, int id) {
        dist[id][start] = 0;
        ways[id][start] = 1;

        vector<bool> vis(n+1, 0);
        priority_queue<pll, vector<pll>, greater<pll> > pq;
        pq.push({ 0, start });

        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if(vis[u]) continue;
            vis[u] = 1;

            for(pii &next : graph[id][u]) {
                int v = next.first;
                int w = next.second;

                if(dist[id][v] > dist[id][u] + w) {
                    dist[id][v] = dist[id][u] + w;
                    ways[id][v] = ways[id][u];
                    pq.push({ dist[id][v], v });
                } else if(dist[id][v] == dist[id][u] + w) {
                    ways[id][v] += ways[id][u];
                }

                ways[id][v] %= mod;
            }
        }
    };

    dijkstra(s, 0);
    dijkstra(t, 1);

    for(Edge &e : edges) {
        ll d = dist[0][e.a] + e.w + dist[1][e.b];

        if(d == dist[0][t]) {
            if(ways[0][t] == (1ll * ways[0][e.a] * ways[1][e.b]) % mod)
                cout << "YES\n";
            else
                cout << (e.w > 1 ? "CAN 1" : "NO") << '\n';
        } else {
            if(d - dist[0][t] + 1 < e.w)
                cout << "CAN " << d - dist[0][t] + 1 << '\n';
            else
                cout << "NO\n";
        }
    }

    return 0;
}