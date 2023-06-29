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

vector<vector<bool> > graph;
vector<bool> vis;

void dfs(int node) {
    vis[node] = true;

    for(int i=0; i<graph.size(); i++)
        if(graph[node][i] && !vis[i]) dfs(i);
}

int main() {
    setIO();

    while(true) {
       int n, m;
       cin >> n >> m;

       if(!n && !m) break;
       vector<pair<int, int> > edges(m);
       bool b = true;

       graph.clear();
       graph.resize(n, vector<bool>(n, false));
       vis.resize(n, false);

       for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = true;
        edges[i] = {a, b};
       }

       for(auto &edge : edges) {
        graph[edge.first][edge.second] = false;
        graph[edge.second][edge.first] = false;

        fill(vis.begin(), vis.end(), false);
        dfs(0);

        for(int i=1; i<n; i++) {
            if(!vis[i]) {
                b = false;
                break;
            }
        }

        graph[edge.first][edge.second] = true;
        graph[edge.second][edge.first] = true;
       }
       cout << (b ? "No" : "Yes") << '\n';
    } 

    return 0;
}