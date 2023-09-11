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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    setIO();

    int n, m;

    while(true) {
        cin >> n >> m;
        if(!n && !m) break;

        ll total = 0;
        ll mst = 0;
        vector<vector<pii> > graph(n+1);

        for(int i=0; i<m; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            total += w;
            graph[a].push_back({ b, w });
            graph[b].push_back({ a, w });
        }

        vector<bool> vis(n, false);
        priority_queue<pll, vector<pll>, greater<pll> > pq;

        pq.push({ 0, 0 });

        while(!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if(vis[u]) continue;
            vis[u] = true;

            mst += d;

            for(pii &v : graph[u]) {
                if(vis[v.first]) continue;
                pq.push({ v.second, v.first });
            }
        }

        cout << total - mst << '\n';
    }

    return 0;
}