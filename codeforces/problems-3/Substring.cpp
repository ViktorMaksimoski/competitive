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
    vector<char> val(n+1);
    vector<vector<int> > dp(n+1, vector<int>(26, 0));
    for(int i=1; i<=n; i++) cin >> val[i];

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    vector<int> topo;
    for(int i=1; i<=n; i++)
        if(!indegree[i]) q.push(i), dp[i][int(val[i]-'a')]++;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        topo.push_back(u);
        for(int &v : graph[u]) {
            indegree[v]--;
            if(!indegree[v]) q.push(v);
        }
    }

    if(topo.size() != n) {
        cout << -1 << '\n';
        return 0;
    }

    for(int &u : topo) {
        for(int &v : graph[u]) {
            for(int i=0; i<26; i++) {
                if(i == int(val[v] - 'a'))
                    dp[v][i] = max(dp[v][i], dp[u][i] + 1);
                else
                    dp[v][i] = max(dp[v][i], dp[u][i]);
            }
        }
    }

    int ans = 0;
    for(int u=1; u<=n; u++)
        for(int i=0; i<26; i++)
            ans = max(ans, dp[u][i]);

    cout << ans << '\n';
    return 0;
}