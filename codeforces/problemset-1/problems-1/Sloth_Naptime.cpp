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

int n;
vector<vector<int> > graph;
vector<vector<int> > up;
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
    for(int j=LOG-1; j>=0; j--)
        if(d & (1 << j)) x = up[x][j];
    return x > 0 ? x : 0;
}

int get_lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    a = jmp(a, depth[a] - depth[b]);
    if(a == b) return a;
    for(int j=LOG-1; j>=0; j--)
        if(up[a][j] != up[b][j])
            a = up[a][j], b = up[b][j];

    return up[a][0];
}

void solve(int a, int b, int c) {
    int lca = get_lca(a, b);
    int path1 = depth[a] - depth[lca];
    int path2 = depth[b] - depth[lca];
    int res;
    if(c <= path1)
        res = jmp(a, c);
    else if(c < path1 + path2)
        res = jmp(b, path2 - (c - path1));
    else
        res = b;

    cout << res << '\n';
}

int main() {
    setIO();

    int q;
    cin >> n;
    graph.resize(n+1);
    up.resize(n+1, vector<int>(LOG, 0));
    depth.resize(n+1, 0);

    for(int i=0; i<n-1; i++) {
         int a, b;
         cin >> a >> b;
         graph[a].push_back(b);
         graph[b].push_back(a);
    }

    up[1][0] = 0;
    dfs(1);

    cin >> q;
    while(q--) {
        int a, b, c;
        cin >> a >> b >> c;
        solve(a, b, c);
    }

    return 0;
}