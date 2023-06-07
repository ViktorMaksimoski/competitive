#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int maxn = 1e6;
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
    vector<vector<pair<int, int>> > graph(n+1);
 
    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
    }
 
    vector<vector<ull> > dist(n+1, vector<ull>(2, 1e18));
    vector<vector<bool> > vis(n+1, vector<bool>(2, false));
    priority_queue<pair<ull, pair<bool, int>>, vector<pair<ull, pair<bool, int>>>, greater<pair<ull, pair<bool, int>>> > pq;
    pq.push({ 0, {0, 1} }); //weight, {used, node}
    dist[1][0] = 0;
 
    while(!pq.empty()) {
        ull weight = pq.top().first;
        int node = pq.top().second.second;
        bool used = pq.top().second.first;
        pq.pop();
 
        if(vis[node][used]) continue;
        vis[node][used] = true;
 
        for(auto &nextNode : graph[node]) {
            ull nextWeight = nextNode.second;
            int next = nextNode.first;
 
            if(!used) {
                ull newPrice = dist[node][used] + nextWeight / 2;
                if(newPrice < dist[next][1]) {
                    dist[next][1] = newPrice;
                    pq.push({ newPrice, {true, next} });
                }
            }
 
            ull price = dist[node][used] + nextWeight;
            if(price < dist[next][used]) {
                dist[next][used] = price;
                pq.push({ price, {used, next} });
            }
        }
    }
 
    cout << dist[n][1] << '\n';
    return 0;
}