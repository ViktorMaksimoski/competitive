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
    setIO("timeline");

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> dp(n+1);
    vector<vector<pair<int, int>> > graph(n+1);
    vector<int> indegree(n+1, 0);
    for(int i=1; i<=n; i++) cin >> dp[i];

    for(int i=0; i<k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        indegree[b]++;
    }

    vector<int> topo;
    queue<int> q;
    for(int i=1; i<=n; i++)
        if(!indegree[i]) q.push(i);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);
        for(auto &next : graph[node]) {
            indegree[next.first]--;
            if(!indegree[next.first])
                q.push(next.first);
        }
    }

    for(int &u : topo) {
        for(auto &v : graph[u]) {
            dp[v.first] = max(dp[v.first], dp[u] + v.second);
        }
    }

    for(int i=1; i<=n; i++) {
        cout << dp[i] << '\n';
    }

    return 0;
}