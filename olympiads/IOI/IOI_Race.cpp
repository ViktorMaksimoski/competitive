#include <bits/stdc++.h>
#include "race.h"
 
#define sz(x) (int)x.size()
using namespace std;
using pii = pair<int, int>;
 
int ans = 1e9, k;
vector<vector<pii> > graph;
vector<int> dist, edges;
vector<map<int, int> > sets;

void precomp(int u, int p, int e, int d) {
    edges[u] = e;
    dist[u] = d;

    for(auto &[v, w] : graph[u]) {
        if(v == p) continue;
        precomp(v, u, e + 1, d + w);
    }
}

void dfs(int u, int p) {
    sets[u][dist[u]] = edges[u];
    for(auto &[v, w] : graph[u]) {
        if(v == p) continue;
        dfs(v, u);

        if(sz(sets[u]) < sz(sets[v])) swap(sets[u], sets[v]);
        for(auto &x : sets[v])
            if(sets[u].count(k + 2 * dist[u] - x.first))
                ans = min(ans, x.second + sets[u][k+2*dist[u]-x.first] - 2 * edges[u]);
        
        for(auto &x : sets[v]) {
            if(sets[u].count(x.first)) sets[u][x.first] = min(sets[u][x.first], x.second);
            else sets[u][x.first] = x.second;
        }
    }
}
 
int best_path(int N, int K, int H[][2], int L[]) {
    k = K;
    graph.resize(N);
    dist.resize(N);
    edges.resize(N);
    sets.resize(N);
    for(int i=0; i<N-1; i++) {
        graph[H[i][0]].push_back({ H[i][1], L[i] });
        graph[H[i][1]].push_back({ H[i][0], L[i] });
    }

    precomp(0, 0, 0, 0);
    dfs(0, 0);
 
    return (ans == 1e9 ? -1 : ans);
}