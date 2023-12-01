#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int LOG = 20;
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}
 
void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    if(name != "") setUSA(name);
}
 
struct Node {
    int node, dist, k, l;
    bool operator>(const Node &x) const {
        if(dist != x.dist) return dist > x.dist;
        if(k != x.k) return (k < x.k);
        return (l < x.l);
    }
};
 
int main() {
    setIO();
 
    int n, x, k, l, m;
    int ans = INT_MAX;
    cin >> n >> x >> k >> l >> m;
    vector<vector<pair<int, int>> > graph(n+1);
 
    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }
 
    vector<vector<vector<int>> > dist(n+10, vector<vector<int>>(k+10, vector<int>(l+10, INT_MAX)));
    vector<vector<vector<bool>> > vis(n+10, vector<vector<bool>>(k+10, vector<bool>(l+10, false)));
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(Node{ 1, 0, k, 0 });
    dist[1][k][0] = 0;
 
    while(!pq.empty()) {
        Node city = pq.top();
        pq.pop();
 
        if(vis[city.node][city.k][city.l]) continue;
        if(city.node == n) ans = min(ans, city.dist);
        if(city.node <= x) city.l = 0;
        vis[city.node][city.k][city.l] = true;
         
        for(auto &next : graph[city.node]) {
            int nextCity = next.first;
            int nextWeight = next.second;
 
            //don't use a power
            if(dist[nextCity][city.k][0] > city.dist + nextWeight) {
                dist[nextCity][city.k][0] = city.dist + nextWeight;
                pq.push(Node{ nextCity, city.dist + nextWeight, city.k, 0 });
            }
 
            //continue with this power
            if(city.l >= nextWeight && dist[nextCity][city.k][city.l-nextWeight] > city.dist) {
                dist[nextCity][city.k][city.l-nextWeight] = city.dist;
                pq.push(Node{ nextCity, city.dist, city.k, city.l - nextWeight });
            }
 
            //use a new power, if possible
            if(city.k-1 >= 0 && l >= nextWeight && dist[city.node][city.k-1][l-nextWeight] > city.dist) {
                dist[nextCity][city.k-1][l-nextWeight] = city.dist;
                pq.push(Node{ nextCity, city.dist, city.k-1, l - nextWeight });
            }
        }
    }
 
    cout << ans << '\n';
    return 0;
}