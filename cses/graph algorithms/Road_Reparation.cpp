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

int main() {
    setIO();

    int n, m, con = 0;
    ll mst = 0;
    cin >> n >> m;

    vector<vector<pair<int, int>> > graph(n+1);
    vector<bool> vis(n+1, false);

    for(int i=0; i<m; i++) {
         int a, b, w;
         cin >> a >> b >> w;
         graph[a].push_back({ b, w });
         graph[b].push_back({ a, w });
    } 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({ 0, 1 });

    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(vis[node]) continue;
        vis[node] = true;
        con++;

        mst += weight;

        for(auto &next : graph[node]) {
            if(!vis[next.first]) pq.push({ next.second, next.first });
        }
    }

    if(con == n) cout << mst << '\n';
    else cout << "IMPOSSIBLE\n";
    return 0;
}