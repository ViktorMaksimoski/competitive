#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using pii = pair<int, int>;

int m, ans2 = 0;
map<int, vector<int> > graph, rev_graph;
set<int> nodes;
set<pii> edges;
vector<vector<int> > G;
vector<int> topo, cmp;
vector<bool> vis(31, 0), bad(31);
vector<bitset<31> > dp1(31);
bool removed[31][31];

void dfs(int u) {
    vis[u] = 1;
    for(int &v : graph[u]) {
        if(vis[v]) continue;
        dfs(v);
    }
    topo.push_back(u);
}

void dfs2(int u) {
    vis[u] = 1;
    G.back().push_back(u);
    for(int &v : rev_graph[u]) {
        if(vis[v]) continue;
        dfs2(v);
    }
}

void init() {
    int n = G.size();
    vector<int> indegree(n+1);
    for(auto &x : rev_graph)
        for(auto &u : x.second)
            indegree[u]++;

    queue<int> q;
    topo.clear();

    for(int i=1; i<=n; i++)
        if(!indegree[i]) q.push(i);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        dp1[u][u] = 1;

        topo.push_back(u);

        for(int &v : rev_graph[u]) {
            indegree[v]--;
            if(!indegree[v]) q.push(v);
        }
    }

    for(int &u : topo)
        for(int &v : rev_graph[u])
            dp1[v] |= dp1[u];
}

void check(int a, int b) {
    int n = G.size();
    removed[a][b] = 1;
    vector<bitset<31> > dp2(31);
    vector<int> indegree(n+1);

    for(auto &x : rev_graph)
        for(auto &u : x.second)
            if(!removed[u][x.first]) indegree[u]++;

    queue<int> q;
    topo.clear();

    for(int i=1; i<=n; i++)
        if(!indegree[i]) q.push(i);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        dp2[u][u] = 1;

        topo.push_back(u);

        for(int &v : rev_graph[u]) {
            if(removed[v][u]) continue;
            indegree[v]--;
            if(!indegree[v]) q.push(v);
        }
    }

    for(int &u : topo)
        for(int &v : rev_graph[u])
            if(!removed[v][u]) dp2[v] |= dp2[u];

    bool ok = 1;
    for(int i=1; i<=n; i++)
        if(dp1[i] != dp2[i]) ok = 0;

    if(ok) ans2++;
    else removed[a][b] = 0;
}

int32_t main() {
    cin >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if(a == b) bad[a] = 1;
        nodes.insert(a);
        nodes.insert(b);
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
    }

    for(auto &x : nodes) {
        if(vis[x]) continue;
        dfs(x);
    }

    reverse(all(topo));
    for(int i=1; i<=30; i++) vis[i] = 0;

    for(int &u : topo) {
        if(vis[u]) continue;
        G.push_back({ });
        dfs2(u);
    }

    int ans = 0;
    cmp.resize(31);
    for(int i=0; i<G.size(); i++) {
        if(G[i].size() == 1) ans += bad[G[i][0]];
        else ans += G[i].size();
        for(int &x : G[i])
            cmp[x] = i + 1;
    }

    for(int i=0; i<G.size(); i++)
        for(int &u : G[i])
            for(int &v : graph[u])
                if(cmp[u] != cmp[v]) edges.insert({ cmp[u], cmp[v]  });

    graph.clear();
    rev_graph.clear();
    for(auto &x : edges) {
        graph[x.first].push_back(x.second);
        rev_graph[x.second].push_back(x.first);
    }

    init();
    for(auto &x : edges)
        check(x.first, x.second);
    cout << ans + edges.size() - ans2 << '\n';
    return 0;
}