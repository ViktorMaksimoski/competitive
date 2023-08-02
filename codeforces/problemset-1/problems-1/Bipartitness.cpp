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
vector<int> nodes;
ll g=0, b=0;

void dfs(int node, int par) {
    if(par == -1) {
        g++;
        nodes[node] = 1;
    } else {
        nodes[node] = 2 - nodes[par] + 1;
        if(nodes[node] == 1) g++;
        else b++;
    }

    for(int &next : graph[node]) {
        if(next == par) continue;
        dfs(next, node);
    }
}

int main() {
    setIO();

    int n;
    cin >> n;
    graph.resize(n);
    nodes.resize(n, -1);

    for(int i=0; i<n-1; i++) {
         int a, b;
         cin >> a >> b;
         a--; b--;
         graph[a].push_back(b);
         graph[b].push_back(a);
    }

    dfs(0, -1);

    cout << g * b - (n - 1) << '\n';
    return 0;
}