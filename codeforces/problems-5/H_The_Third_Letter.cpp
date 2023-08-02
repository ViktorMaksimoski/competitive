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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii> > graph(n+1);
    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, -w });
    }

    vector<bool> vis(n+1, false);
    vector<ll> dist(n+1, 0);
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(vis[i]) continue;
        vis[i] = true;
        q.push(i);
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(pii &v : graph[u]) {
                if(!vis[v.first]) {
                    vis[v.first] = true;
                    q.push(v.first);
                    dist[v.first] = dist[u] + v.second;
                }

                if(dist[v.first] != dist[u] + v.second) {
                    cout << "NO\n";
                    return ;
                }
            }
        }
    }

    cout << "YES\n";
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}