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

//dp[i][0] - the node is black
//dp[i][1] - the node is white
void dfs(int u, int p) {
    dp[u][0] = 1;
    dp[u][1] = 1;

    for(int &v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[u][0] *= dp[v][1];
        dp[u][0] %= mod;
    }

    for(int &v : graph[u]) {
        if(v == p) continue;
        dp[u][1] *= (dp[v][0] + dp[v][1]);
        dp[u][1] %= mod;
    }
}

int main() {
    setIO();

    int n;
    cin >> n;
    graph.resize(n+1);
    dp.resize(n+1, vector<ll>(2, 0));

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 1);
    cout << (dp[1][0] + dp[1][1]) % mod << '\n';
    return 0;
}