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

    int t, n, m;
    cin >> t >> n;
    vector<int> val(n);
    for(int &x : val) cin >> x;

    vector<vector<int> > graph(n);
    cin >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vector<ll> dist(n, 1e18);
    vector<bool> vis(n, false);
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    pq.push({ -t, 0 });
    dist[0] = -t - val[0];

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(vis[u] || dist[u] > 0) continue;
        vis[u] = true;

        cout << u << " " << -dist[u] << '\n';
        for(int &v : graph[u]) {
            ll newDist = dist[u] - val[v];
            if(newDist > 0) continue;
            if(dist[v] > newDist) {
                dist[v] = newDist;
                pq.push({ dist[v], v });
            }
        }
    }

    if(dist[n-1] == 1e18) cout << "NE\n";
    else cout << -dist[n-1] << '\n';
    return 0;
}