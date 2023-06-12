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

vector<vector<int> > graph;
vector<int> vis, color;
bool pos = true;

void dfs(int node, int c) {
    vis[node] = true;
    color[node] = c;

    for(int &next : graph[node]) {
        if(vis[next]) {
            if(color[next] == c) pos = false;
        } else dfs(next, 1-c);
    }
}

int main() {
    setIO();

    int n, m;
    cin >> n >> m; 
    graph.resize(n);
    vis.resize(n, false);
    color.resize(n, -1);

    for(int i=0; i<m; i++) {
         int a, b;
         cin >> a >> b;
         a--; b--;
         graph[a].push_back(b);
         graph[b].push_back(a);
    }

    for(int i=0; i<n && pos; i++)
        if(!vis[i]) dfs(i, 0);

    if(!pos) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int &c : color) cout << c + 1 << " ";
    return 0;
}