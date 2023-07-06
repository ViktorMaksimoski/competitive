#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

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

bool compat(vector<int> &v1, vector<int> &v2) {
    for(int i=0; i<sz(v1); i++) {
        if(v1[i] >= v2[i]) return false;
    }

    return true;
}

int main() {
    setIO();

    int n, k;

    while(cin >> n >> k) {
        vector<vector<int> > v(n, vector<int>(k));
        for(int i=0; i<n; i++)
            for(int j=0; j<k; j++)
                cin >> v[i][j];

        for(int i=0; i<n; i++) sort(all(v[i]));

        vector<vector<int> > graph(n);
        vector<int> indegree(n, 0);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(compat(v[i], v[j]) && i != j)
                    graph[i].push_back(j), indegree[j]++;

        // for(int i=0; i<n; i++) {
        //     for(int &j : graph[i]) {
        //         cout << i << " -> " << j << '\n';
        //     }
        // }

        queue<int> q;
        vector<int> topo;
        for(int i=0; i<n; i++)
            if(!indegree[i]) q.push(i);

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            topo.push_back(u);
            for(int &v : graph[u])
                if(--indegree[v] == 0) q.push(v);
        }

        vector<int> dp(n, 0);
        vector<int> par(n, -1);

        int ans = 0, node = 0;
        for(int &u : topo) {
            for(int &v : graph[u]) {
                if(dp[v] < dp[u] + 1) {
                    dp[v] = dp[u] + 1, par[v] = u; 
                    if(dp[v] > ans) {
                        ans = dp[v];
                        node = v;
                    }
                }
            }
        }

        cout << ans + 1 << '\n';
        vector<int> res;
        while(par[node] != -1) {
            res.push_back(node);
            node = par[node];
        }
        res.push_back(node);
        reverse(all(res));
        for(int &x : res) cout << x + 1 << " ";
        cout << '\n';
    } 

    return 0;
}