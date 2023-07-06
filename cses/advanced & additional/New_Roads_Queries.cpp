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
 
template <class T>
struct DSU {
    vector<T> parent;
    vector<int> size;
    int components;
 
    DSU(int n) {
        parent.resize(n+1);
        for(int i=0; i<n+1; i++) parent[i] = i;
        size.resize(n+1, 1);
        components = n;
    }
 
    T find(T x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
 
    T getSize(T x) {
        return size[find(x)];
    }
 
    bool uni(T a, T b) {
        T leaderA = find(a), leaderB = find(b);
 
        if(leaderA == leaderB) {
            return false;
        }
 
        components--;
 
        if(size[leaderA] > size[leaderB]) swap(leaderA, leaderB);
 
        parent[leaderA] = leaderB;
        size[leaderB] += size[leaderA];
        return true;
    }
 
    int getComponents() {
        return components;
    }
 
    bool same_set(T a, T b) {
        return find(a) == find(b);
    }
};
 
vector<vector<pair<int, int>> > graph;
vector<int> depth;
vector<vector<int> > up, mx;
vector<int> comp;
 
void dfs(int u, int p, int c) {
    comp[u] = c;
    for(int i=1; i<20; i++) {
        up[u][i] = up[ up[u][i-1] ][i-1];
        mx[u][i] = max({ mx[u][i], mx[ up[u][i-1] ][i-1], mx[u][i-1] });
    }
 
    for(auto &next : graph[u]) {
        int v = next.first;
        int w = next.second;
        if(v == p) continue;
 
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        mx[v][0] = w;
        dfs(v, u, c);
    }
}
 
pair<int, int> jmp(int x, int d) {
    int ans = 0;
    for(int j=19; j>=0; j--)
        if(d & (1 << j)) ans = max(ans, mx[x][j]), x = up[x][j];
    return make_pair(x, ans);
}
 
int get_day(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
 
    int ans = -1;
    auto res = jmp(a, depth[a] - depth[b]);
    a = res.first;
    ans = res.second;

    if(a == b)
        return ans;
 
    for(int j=19; j>=0; j--) {
        if(up[a][j] != up[b][j]) {
            ans = max(ans, mx[a][j]);
            ans = max(ans, mx[b][j]);
            a = up[a][j];
            b = up[b][j];
        }
    }

    if(up[a][0] != up[b][0])
        return -1;
 
    return max({ ans, mx[a][0], mx[b][0] });
}
 
int main() {
    setIO();
 
    int n, m, q;
    cin >> n >> m >> q;
    DSU<int> dsu(n);
    graph.resize(n+1);
    depth.resize(n+1, -1);
    comp.resize(n+1, -1);
    up.resize(n+1, vector<int>(20, 0));
    mx.resize(n+1, vector<int>(20, 0));
 
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if(dsu.uni(a, b)) {
            graph[a].emplace_back(b, i+1);
            graph[b].emplace_back(a, i+1);
        }
    }
 
    for(int i=1; i<=n; i++) {
        if(comp[i] != -1) continue;
        up[i][0] = i;
        depth[i] = 0;
        dfs(i, 0, i);
    }
 
    while(q--) {
        int a, b;
        cin >> a >> b;
        
        int ans = get_day(a, b);
        cout << ans << '\n';
    }
 
    return 0;
}