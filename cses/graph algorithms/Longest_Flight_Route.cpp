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

int main() {
    setIO();

    int n, m;
    cin >> n >> m;

    vector<vector<int> > graph(n+1);
    vector<int> indegree(n+1, 0);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    if(graph[1].size() == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    //dfs
    stack<int> s;
    vector<bool> vis(n+1, false);
    s.push(1);
    vis[1] = true;
    while(!s.empty()) {
        int node = s.top();
        s.pop();

        for(int &next : graph[node]) {
            if(vis[next]) continue;
            s.push(next);
            vis[next] = true;
        }
    }

    if(!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    queue<int> q;
    vector<int> topo;
    for(int i=1; i<=n; i++)
        if(!indegree[i]) q.push(i);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for(int &next : graph[node]) {
            indegree[next]--;
            if(!indegree[next]) q.push(next);
        }
    }

    vector<int> dp(n+1, -1);
    vector<int> par(n+1, -1);
    dp[1] = 1;

    for(int &u : topo) {
        for(int &v : graph[u]) {
            if(dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
                par[v] = u;
            }
        }
    }

    if(dp[n] == -1 || topo.size() != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int u = n;
    vector<int> path;
    while(u != -1) {
        path.push_back(u);
        u = par[u];
    }

    cout << dp[n] << '\n';
    for(int i=path.size()-1; i>=0; i--)
        cout << path[i] << " ";
    return 0;
}