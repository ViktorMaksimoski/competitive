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

vector<int> v;
vector<vector<int> > graph;
vector<vector<ll> > dp;
int n;

void dfs(int node) {
    ll sum = 0;

    for(int &next : graph[node]) {
        dfs(next);
        sum += max(dp[next][0], dp[next][1]);
    }

    for(int &next : graph[node]) {
        if(v[next] >= v[node])
            dp[node][0] = max(dp[node][0], sum - max(dp[next][0], dp[next][1]) + dp[next][0] + v[next] - v[node]);
        if(v[node] >= v[next])
            dp[node][1] = max(dp[node][1], sum - max(dp[next][0], dp[next][1]) + dp[next][1] - v[next] + v[node]);

        dp[node][0] = max(sum, dp[node][0]);
        dp[node][1] = max(sum, dp[node][1]);
    }
    
}

int main() {
    setIO();

    cin >> n;
    v.resize(n+1);
    graph.resize(n+1); 
    dp.resize(n+1, vector<ll>(2, 0));

    for(int i=1; i<=n; i++) cin >> v[i];
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    dfs(1);

    cout << max(dp[1][0], dp[1][1]) << '\n';
    return 0;
}