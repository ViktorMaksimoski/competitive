#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int maxn = 1e6;
#define ii pair<int, int>
using namespace std;
 
void setUSA(string name)
{
    string inName = name + ".in";
    string outName = name + ".out";
    freopen(inName.c_str(), "r", stdin);
    freopen(outName.c_str(), "w", stdout);
}
 
void setIO(string name = "")
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(name != "") setUSA(name);
}
 
int main()
{
    setIO();
 
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll> > > graph(n+1);
    vector<bool> vis(n+1);
    vector<ull> dist(n+1, 18 * 1e18);
    //broj na nacini da se dostigne najmala cena
    vector<int> ways(n+1, 0);
 
    vector<int> minPrice(n+1, 0);
    vector<int> maxPrice(n+1, 0);
 
    //grafot e dvonasocen
    for(int i=0; i<m; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
    }
 
    //dijkstra
    priority_queue<pair<ull, int>, vector<pair<ull, int>>, greater<pair<ull, int>> > pq;
    pq.push({ 0, 1 }); // weight, node
    // dist - jasno, ways[1] = 1, slicno kako kaj dinamicko za najkratok pat vo grid
    dist[1] = 0; ways[1] = 1;
 
    while(!pq.empty()) {
        ll weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
 
        if(vis[node]) continue;
        vis[node] = true;
 
        for(pair<int, ll> &nextNode : graph[node]) {
            ll nextWeight = nextNode.second;
            int next = nextNode.first;
 
            if(nextWeight + dist[node] == dist[next]) {
                ways[next] = ((ways[next] % mod) + (ways[node] % mod)) % mod;
                minPrice[next] = min(minPrice[next], minPrice[node] + 1);
                maxPrice[next] = max(maxPrice[next], maxPrice[node] + 1);
            }
            else if(nextWeight + dist[node] < dist[next]) {
                ways[next] = ways[node] % mod;
                minPrice[next] = minPrice[node] + 1;
                maxPrice[next] = maxPrice[node] + 1;
                dist[next] = nextWeight + dist[node];
                pq.push({ dist[next], next });
            }
        }
    }
 
    cout << dist[n] << " " << ways[n] << " " << minPrice[n] << " " << maxPrice[n] << '\n';
    return 0;
}