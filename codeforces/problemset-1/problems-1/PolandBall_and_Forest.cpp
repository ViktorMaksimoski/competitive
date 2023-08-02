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

void dfs(int node) {
    vis[node] = true;

    for(int &next : graph[node]) {
        if(vis[next]) continue;
        dfs(next);
    }
}

int main() {
    setIO();

    cin >> n;
    int ans = 0;
    graph.resize(n+1);
    vis.resize(n+1, false);

    if(n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        graph[a].push_back(i);
        graph[i].push_back(a);
    }

    for(int i=1; i<=n; i++) {
        if(vis[i]) continue;
        ans++;
        dfs(i);
    }

    cout << ans << '\n';
    return 0;
}