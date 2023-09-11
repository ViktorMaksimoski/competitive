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

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct Edge {
    int a, b, w;

    bool operator<(Edge &e) {
        return w < e.w;
    }
};

vector<int> ans;

void solve(int tc) {
    int n, k;
    cin >> n >> k;

    vector<vector<pii> > graph(n+1);
    vector<Edge> edges;

    for(int i=1; i<=n-1; i++) {
        for(int j=0; j<n-i; j++) {
            int x;
            cin >> x;
            edges.push_back(Edge{ i, i+j+1, x });
        }
    }

    sort(all(edges));

    auto dijkstra = [&](int a, int b) {
        vector<ll> dist(n+1, 1e18);
        dist[a] = 0;

        vector<bool> vis(n+1, false);
        priority_queue<pll, vector<pll>, greater<pll> > pq;

        pq.push({ 0, a });

        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if(vis[u]) continue;
            vis[u] = true;

            for(auto &next : graph[u]) {
                int v = next.first;
                int d = next.second;
                if(dist[v] > dist[u] + d) {
                    dist[v] = dist[u] + d;
                    pq.push({ dist[v], v });
                }
            }
        }

        return dist[b];
    };

    int cnt = 0;

    for(Edge &e : edges) {
        ll d = dijkstra(e.a, e.b);

        if(e.w < d) {
            graph[e.a].push_back({ e.b, e.w });
            graph[e.b].push_back({ e.a, e.w });
            cnt++;
            continue;
        } 

        if(e.w > d) {
            ans.push_back(tc);
            return ;
        }
    }

    if(cnt > k) ans.push_back(tc);
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    for(int i=1; i<=t; i++)
        solve(i);

    cout << ans.size() << '\n';
    for(int &x : ans) cout << x << '\n';
    return 0;
}