#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<vector<pii> > graph;
vector<int> color;
bool ok = 1;
int ans = 0;
int imp, crew;

void dfs(int u, int c) {
    color[u] = c;
    if(c == 1) crew++;
    else imp++;

    for(pii &e : graph[u]) {
        int v = e.first;
        int w = e.second;

        int newC = (w == 1 ? 3 - c : c);

        if(!color[v]) dfs(v, newC);
        else if(newC != color[v]) ok = 0;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    graph.clear();
    graph.resize(n+1);
    color.clear();
    color.resize(n+1, 0);
    ok = 1, ans = 0;

    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> w >> a >> b;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    for(int i=1; i<=n; i++) {
        if(color[i] != 0) continue;
        imp = 0, crew = 0;
        dfs(i, 1);
        ans += max(imp, crew);
    }

    cout << (ok ? ans : -1) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}