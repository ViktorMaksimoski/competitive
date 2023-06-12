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

vector<vector<int> > graph, graph2;
vector<bool> vis;

void dfs(int node) {
    vis[node] = true;
    
    for(int &next : graph[node])
        if(!vis[next]) dfs(next);
}

void dfs2(int node) {
    vis[node] = true;
    
    for(int &next : graph2[node])
        if(!vis[next]) dfs2(next);
}

int main() {
    setIO();

    int n, m;
    cin >> n >> m; 
    graph.resize(n);
    graph2.resize(n);
    vis.resize(n, false);

    for(int i=0; i<m; i++) {
         int a, b;
         cin >> a >> b;
         a--; b--;
         graph[a].push_back(b);
         graph2[b].push_back(a);
    }

    dfs(0);
    for(int i=1; i<n; i++) {
        if(!vis[i]) {
            cout << "NO\n";
            cout << 1 << " " << i+1 << '\n';
            return 0;
        }
    }

    fill(vis.begin(), vis.end(), false);
    dfs2(0);

    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            cout << "NO" << '\n';
            cout << i+1 << " " << 1 << '\n';
            return 0;
        }
    }

    cout << "YES" << '\n';
    return 0;
}