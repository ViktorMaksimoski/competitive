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

    int n, m, s, t, prop;
    cin >> n >> m;
    vector<vector<pii> > graph(n+1);

    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    cin >> s >> t >> prop;

    vector<ll> dist(n+1, 1e18);
    vector<bool> vis(n+1, false);
    vector<int> par(n+1, -1);
    priority_queue<pll, vector<pll>, greater<pll> > pq;

    dist[s] = 1;
    pq.push({ 1, s });

    while(!pq.empty()) {
        int u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = true;

        for(auto &v : graph[u]) {
            if(dist[v.first] > 1ll * dist[u] * v.second) {
                dist[v.first] = 1ll * dist[u] * v.second;
                pq.push({ dist[v.first], v.first });
                par[v.first] = u;
            }
        }
    }

    if(dist[t] == 1e18) {
        cout << "NE\nNE\n";
    } else {
        cout << dist[t] << '\n';
        if(dist[t] > prop) {
            cout << "NE\n";
            return 0;
        }
        int curr = t;
        vector<int> ans;
        while(curr != -1) {
            ans.pb(curr);
            curr = par[curr];
        }

        reverse(all(ans));
        for(int &x : ans) cout << x << " ";
    }

    return 0;
}