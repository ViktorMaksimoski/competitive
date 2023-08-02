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

int n, k;
ll ans = 0;
vector<vector<int> > graph;
vector<vector<ll> > dp;

//Paths with length k in the subtree int u
//Obviously, dp[u][0] = 1; (the path is u - u)
//Now, if we connect node U to a child V, then
//All paths from a child of V to V itself
//will be part of path from the child to U
//also dist(U - V) = 1
//so for all i = [0, k], dp[U][i+1] += dp[V][i];
//now the total paths with length i
//ending in the subtree in u is
//dp[u][i] * dp[v][k-i-1], since
//i + (k-i-1) + 1 = k
void dfs(int u, int p) {
    dp[u][0] = 1;
    for(int &v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
        for(int i=0; i<k; i++)
            ans += (dp[u][i] * dp[v][k-i-1]);
        for(int i=0; i<k; i++)
            dp[u][i+1] += dp[v][i];
    }
}

int main() {
    setIO();

    cin >> n >> k;
    graph.resize(n+1);
    dp.resize(n+1, vector<ll>(k+1, 0));

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 1);
    cout << ans << '\n';
    return 0;
}