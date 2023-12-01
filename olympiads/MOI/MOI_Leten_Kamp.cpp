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
 
unordered_map<int, int> comp;
vector<vector<pii> > graph;
 
int32_t main() {
    setIO();
 
    int n, k, r;
    cin >> n >> k >> r;
    vector<int> imp(k+1, 0);
    graph.resize(n);
     
    for(int i=1; i<=k; i++) {
        cin >> imp[i];
    }
 
    sort(all(imp));
    for(int i=0; i<r; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(mp(b, c));
        graph[b].push_back(mp(a, c));
    }
 
    int id = 0;
    for(int &x : imp) comp[x] = id++;
 
    vector<vector<ll> > dist(k+1, vector<ll>(n, 1e18));
    vector<bool> vis(n, false);
 
    for(int i=0; i<k+1; i++) {
        int curr = imp[i];
        fill(all(vis), 0);
        priority_queue<pll, vector<pll>, greater<pll> > pq;
        pq.push(mp(0, curr));
        dist[i][curr] = 0;
 
        while(!pq.empty()) {
            int u = pq.top().second;
            ll d = pq.top().first;
            pq.pop();
 
            if(vis[u]) continue;
            vis[u] = true;
 
            for(auto &v : graph[u]) {
                if(dist[i][v.first] > dist[i][u] + v.second) {
                    dist[i][v.first] = v.second + dist[i][u];
                    pq.push({ dist[i][v.first], v.first });
                }
            }
        }
    }
 
    ll ans = 1e18;
    //dp[x][mask] - min dist od 0 do x, posetuvajki gi gradovite vo mask
    vector<vector<ll> > dp(k+1, vector<ll>(1<<(k+1), 1e18));
    dp[0][1<<0] = 0;
 
    for(int s=1; s<(1<<(k+1)); s++) {
        for(int i=0; i<k+1; i++) {
            if((s & 1) == 0) continue;
            if((s & (1<<i)) == 0) continue;
 
            for(int j=0; j<k+1; j++) {
                if(i == j) continue;
                if(s & (1 << j)) {
                    dp[i][s] = min(dp[i][s], dp[j][s^(1<<i)] + dist[i][imp[j]]);
                }
            }
 
            string mask = bitset<5>(s).to_string();
            //cout << i << " " << mask << " " << dp[i][s] << '\n';
 
            if(s == (1<<(k+1))-1) ans = min(ans, dp[i][s] + dist[0][imp[i]]);
        }
    }
 
    cout << ans << '\n';
    return 0;
}