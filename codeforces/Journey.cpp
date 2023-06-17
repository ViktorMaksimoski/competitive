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

int n;
vector<vector<int> > graph;
vector<bool> vis;
vector<int> leaves;
vector<int> depth;
vector<long double> probability;

void dfs(int node, long double pb) {
    vis[node] = true;
    probability[node] = pb;
    int nb = 0;

    for(int &next : graph[node]) {
        if(vis[next]) continue;
        nb++;
        depth[next] = depth[node] + 1;
    }

    for(int &next : graph[node]) {
        if(vis[next]) continue;
        long double np = pb / double(nb);
        dfs(next, np);
    }

    if(nb == 0) {
        leaves.emplace_back(node);
    }
}

int main() {
    setIO();

    cin >> n; 
    graph.resize(n+1);
    vis.resize(n+1, false);
    depth.resize(n+1, 0);
    probability.resize(n+1, 0);

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 1);
    long double sum = 0;
    
    for(int &x : leaves)
        sum += (depth[x] * probability[x]);

    cout << setprecision(15) << fixed << sum << '\n';
    return 0;
}