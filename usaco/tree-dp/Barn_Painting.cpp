#include <bits/stdc++.h>
#define sz(x) x.size()
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

vector<vector<int> > graph;
vector<vector<ll> > dp;

void dfs(int u, int p) {
    for(int &v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[u][0] *= ((dp[v][1] + dp[v][2]) % mod);
        dp[u][1] *= ((dp[v][0] + dp[v][2]) % mod);
        dp[u][2] *= ((dp[v][1] + dp[v][0]) % mod);
        dp[u][0] %= mod;
        dp[u][1] %= mod;
        dp[u][2] %= mod;
    }
}

int main() {
    setIO("barnpainting");

    int n, m;
    cin >> n >> m;
    graph.resize(n+1);
    dp.resize(n+1, vector<ll>(3, 1));

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        b--;
        for(int j=0; j<3; j++)
            if(j != b) dp[a][j] = 0;
    }

    dfs(1, 1);
    cout << (dp[1][0] + dp[1][1] + dp[1][2]) % mod << '\n';
    return 0;
}