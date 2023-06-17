#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
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

int n;
vector<vector<int> > graph;
vector<int> depth;
int x = -1, curr = -1;

void dfs(int node, int par) {
    if(depth[node] > curr) {
        x = node;
        curr = depth[node];
    }

    for(int &next : graph[node]) {
        if(next == par) continue;
        depth[next] = depth[node] + 1;
        dfs(next, node);
    }
}

int main() {
    setIO();

    cin >> n;
    graph.resize(n+1);
    depth.resize(n+1, 0);

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1,0);
    
    int ep = x;
    x = -1, curr = -1;
    fill(depth.begin(), depth.end(), 0);

    dfs(ep, 0);
    cout << curr << '\n';
    return 0;
}