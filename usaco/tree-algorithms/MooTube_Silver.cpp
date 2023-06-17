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

int n, q;
vector<vector<pair<int, int>> > graph;
vector<bool> vis;

int dfs(int node, int rel) {
    vis[node] = true;
    int sum = 1;

    for(auto &next : graph[node]) {
        if(vis[next.first]) continue;
        if(next.second < rel) continue;
        sum += dfs(next.first, rel);
    }

    return sum;
}

int main() {
    setIO("mootube");

    cin >> n >> q;
    graph.resize(n+1);
    vis.resize(n+1, false);
    for(int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    while(q--) {
        fill(vis.begin(), vis.end(), false);
        int k, v;
        cin >> k >> v;
        cout << dfs(v, k) - 1 << '\n';
    }

    return 0;
}