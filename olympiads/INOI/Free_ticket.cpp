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

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;

    vector<vector<pii> > graph(n+1);
    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    ll ans = 0;

    for(int i=1; i<=n; i++) {
        priority_queue<pll, vector<pll>, greater<pll> > pq;
        vector<bool> vis(n+1);
        vector<ll> dist(n+1, 1e18);

        pq.push({ 0, i });
        dist[i] = 0;

        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if(vis[u]) continue;
            vis[u] = 1;

            for(pii &e : graph[u]) {
                int v = e.first;
                int w = e.second;
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({ dist[v], v });
                }
            }
        }

        for(int j=1; j<=n; j++) {
            if(!vis[j]) continue;
            ans = max(ans, dist[j]);
        }
    }

    cout << ans << '\n';
    return 0;
}