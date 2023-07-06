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
vector<int> dp;
vector<int> sub;

void clear() {
    graph.clear();
    sub.clear();
    dp.clear();
}

void resize(int n) {
    graph.resize(n+1);
    dp.resize(n+1, 0);
    sub.resize(n+1, 0);
}

void getSub(int u, int p) {
    sub[u] = 1;
    for(int &v : graph[u]) {
        if(v == p) continue;
        getSub(v, u);
        sub[u] += sub[v];
    }
}

void dfs(int u, int p) {
    int l = 0, r = 0;
    for(int &v : graph[u]) {
        if(v == p) continue;
        if(l == 0) l = v;
        else r = v;
    }

    for(int &v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
    }

    dp[u] = max({ dp[u], dp[l] + sub[r] - 1, dp[r] + sub[l] - 1 });
}

void solve() {
    int n;
    cin >> n;
    clear();
    resize(n);

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    getSub(1, 1);
    dfs(1, 1);
    cout << dp[1] << '\n';
}

int main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}