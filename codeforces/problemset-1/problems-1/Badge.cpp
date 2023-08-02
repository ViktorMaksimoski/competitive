#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
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
vector<int> graph, ans;
vector<bool> vis;

void dfs(int node) {
    if(vis[node]) {
        ans.push_back(node+1);
        return ;
    }

    vis[node] = true;
    dfs(graph[node]);
}

int main() {
    setIO();

    cin >> n;
    graph.resize(n);
    vis.resize(n, false);

    for(int i=0; i<n; i++) {
        cin >> graph[i];
        graph[i]--;
    }

    for(int i=0; i<n; i++) {
        fill(vis.begin(), vis.end(), false);
        dfs(i);
        //cout << "-------\n";
    }

    for(int &x : ans)
        cout << x << " ";
    return 0;
}