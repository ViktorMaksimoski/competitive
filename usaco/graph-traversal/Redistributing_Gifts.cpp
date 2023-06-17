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
vector<vector<bool> > vis;

void dfs(int node, int pr) {
    vis[node][pr] = true;

    for(int &next : graph[pr]){
        if(vis[node][next]) continue;
        dfs(node, next);
    }
}

int main() {
    setIO();

    int n;
    cin >> n;
    graph.resize(n+1);
    vis.resize(n+1, vector<bool>(n+1, false));

    for(int i=1; i<=n; i++) {
        for(int j=0; j<n; j++) {
            int x;
            cin >> x;
            graph[i].push_back(x);
        }

        while(graph[i].back() != i)
            graph[i].pop_back();
    }

    // for(int i=1; i<=n; i++) {
    //     for(int &j : graph[i]) {
    //         cout << i << " -> " << j << '\n';
    //     }
    // }

    for(int i=1; i<=n; i++) {
        if(vis[i][i]) continue;
        dfs(i, i);
    }

    for(int i=1; i<=n; i++) {
        for(int &j : graph[i]) {
            if(!vis[j][i]) continue;
            cout << j << '\n';
            break;
        }
    }

    return 0;
}