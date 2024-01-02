#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
   
struct DSU {
    int n;
    vector<int> par;
    
    DSU(int &_n) {
        n = _n + 2;
        par.resize(n+1);
        for(int i=1; i<=n; i++)
            par[i] = i;
    }
    
    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    
    bool uni(int a, int b) {
        a = find(a);
        b = find(b);
    
        if(a == b) return 0;
        par[a] = b;
    
        return 1;
    }
};
   
int n, cnt = 1, q, last;
vector<vector<int> > graph_all, graph, graph_rev;
vector<int> indegree, comp, endPoint, ans;
vector<pii> qus;
vector<bool> bad, vis;
   
void dfs(int u) {
    if(vis[u]) return ;
    vis[u] = 1;
    comp[u] = cnt;
    endPoint[cnt] = last;
       
    for(int &x : graph[u])
        dfs(x);
}
   
void resize() {
    graph_all.resize(n+1);
    graph.resize(n+1);
    graph_rev.resize(n+1);
    indegree.resize(n+1);
    comp.resize(n+1);
    endPoint.resize(n+1);
    bad.resize(n+1);
    vis.resize(n+1);
}
   
void readGraph() {
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if(x) graph_all[i].push_back(x);
        else bad[i] = 1;
    }
}
   
void readQueries() {
    cin >> q;
    qus.resize(q);
    for(pii &x : qus) {
        cin >> x.first >> x.second;
        if(x.first == 2) bad[x.second] = 1;
    }
}
   
void makeGraph() {
    for(int i=1; i<=n; i++) {
        if(bad[i]) continue;
        graph[graph_all[i][0]].push_back(i);
        indegree[i]++;
    }
}
   
void findComps() {
    for(int i=1; i<=n; i++) {
        if(indegree[i]) continue;
        last = i;
        dfs(i);
        cnt++;
    }
   
    for(int i=1; i<=n; i++) {
        if(vis[i]) continue;
        dfs(i);
        endPoint[cnt++] = -1;
    }
}
   
void process() {
    DSU dsu(cnt);
   
    for(int i=q-1; i>=0; i--) {
        int t = qus[i].first;
        int u = qus[i].second;
   
        if(t == 2) {
            int v = graph_all[u][0];
            //cout << u << " " << v << ": " << dsu.find(comp[u]) << " " << dsu.find(comp[v]) << '\n';
            if(!dsu.uni(comp[u], comp[v]))
                endPoint[comp[u]] = -1;
        } else {
            int x = dsu.find(comp[u]);
            ans.push_back(endPoint[x]);
        }
    }
}
   
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    cin >> n;
    resize();
   
    readGraph();
    readQueries();
    makeGraph();
    findComps();
    process();
   
    reverse(ans.begin(), ans.end());
    for(int &x : ans) {
        if(x == -1) cout << "CIKLUS\n";
        else cout << x << '\n';
    }
    return 0;
}