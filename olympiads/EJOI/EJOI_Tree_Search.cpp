#include <bits/stdc++.h>
#include "stub.h"

using namespace std;
using ll = long long;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n;
int ans = 0;
vector<vector<int> > graph;
vector<int> par, sub;
vector<bool> is_removed;

int get_sub(int u, int p) {
    sub[u] = 1;
    for(int &v : graph[u]) {
        if(v == p) continue;
        if(is_removed[v]) continue;
        sub[u] += get_sub(v, u);
    }
    return sub[u];
}

int get_centroid(int u, int sz, int p) {
    for(int &v : graph[u]) {
        if(v == p) continue;
        if(is_removed[v]) continue;
        if(sub[v] * 2 > sz)
            return get_centroid(v, sz, u);
    }
    return u;
}

void decomp(int u) {
    if(is_removed[u]) return;
    int centroid = get_centroid(u, get_sub(u, u), u);

    int res = ask(centroid);

    is_removed[centroid] = true;

    if(res == 1) {
        ans = u;
        vector<int> deca;

        for(int &v : graph[centroid]) {
            if(v == par[centroid]) continue;
            if(is_removed[v]) continue;
            deca.push_back(v);
        }

        if(deca.size() == 1) {
            decomp(deca.back());
        } else if(deca.size() == 2) {
            if(ask(deca[1])) decomp(deca[1]);
            else decomp(deca[0]);
        }
    } else {
        decomp(par[centroid]);
    }
}

int solve(int N, vector<int> p) {
    n = N;
    graph.resize(n+1);
    par.resize(n+1);
    sub.resize(n+1);
    is_removed.resize(n+1, false);

    for(int i=0; i<n-1; i++) {
        graph[i+2].push_back(p[i]);
        graph[p[i]].push_back(i+2);
        par[i+2] = p[i];
    }

    decomp(1);

    return ans;
}