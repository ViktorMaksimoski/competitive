#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 2e5 + 5;
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
 
int n, q;
vector<vector<int> > graph, up;
vector<int> depth;
 
void dfs(int v) {
	for(int i=1; i<LOG; i++) up[v][i] = up[up[v][i - 1]][i - 1];
 
	for (int x : graph[v]) {
		if (x != up[v][0]) {
			depth[x] = depth[up[x][0] = v] + 1;
			dfs(x);
		}
	}
}
 
int jmp(int x, int d) {
    for(int j=0; j<LOG; j++)
        if(d & (1 << j)) x = up[x][j];
 
    return x;
}
 
int get_lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
 
    a = jmp(a, depth[a] - depth[b]);
    if(a == b) return a;
 
    for(int j=LOG-1; j>=0; j--)
        if(up[a][j] != up[b][j]) a = up[a][j], b = up[b][j];
 
    return up[a][0];
}
 
int main() {
    setIO();
 
    cin >> n >> q; 
    graph.resize(n+1);
    up.resize(n+1, vector<int>(LOG, 0));
    depth.resize(n+1, 0);
 
    for(int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    up[1][0] = 1;
    dfs(1);
 
    while(q--) {
        int a, b;
        cin >> a >> b;
 
        int lca = get_lca(a, b);
        cout << depth[a] + depth[b] - 2*depth[lca] << '\n';
    }
 
    return 0;
}