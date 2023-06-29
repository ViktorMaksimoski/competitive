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

vector<vector<pair<int, int> > > graph;
vector<int> depth;
vector<vector<int> > up, day;

void dfs(int node, int par) {
    for(int i=1; i<20; i++) {
        up[node][i] = up[ up[node][i-1] ][i-1];
        day[node][i] = max(day[node][i-1], day[up[node][i-1]][i-1]);
    }

    for(auto &next : graph[node]) {
        if(next.first == par) continue;
        depth[next.first] = depth[node] + 1;
        up[next.first][0] = node;
        day[next.first][0] = next.second;
        dfs(next.first, node);
    }
}

pair<int, int> jmp(int x, int d) {
    int ans = 0;
    for(int j=19; j>=0; j--)
        if(d & (1 << j)) ans = max(ans, day[x][j]), x = up[x][j];
    return { x, ans };
}

int query(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    int ans = 0;
    auto j = jmp(a, depth[a] - depth[b]);
    a = j.first, ans = j.second;

    for(int i=19; i>=0; i--) {
        if(up[a][i] != up[b][i]) {
            ans = max({ ans, day[a][i], day[b][i] });
            a = up[a][i], b = up[a][i];
        }
    }

    //cout << "query: " << a << " " << b << '\n';
    return max({ ans, day[a][0], day[b][0] });
}

int main() {
    setIO();

    int n, m, q;
    cin >> n >> m >> q; 
    DSU<int> dsu(n);
    graph.resize(n+1);
    depth.resize(n+1, 0);
    up.resize(n+1, vector<int>(20, 0));
    day.resize(n+1, vector<int>(20, 0));

    //we create some sort of MST
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if(dsu.uni(a, b)) {
            graph[a].push_back({ b, i+1 });
            graph[b].push_back({ a, i+1 });
        }
    }

    for(int i=1; i<=n; i++) {
        if(graph[i].size() == 0) continue;
        up[i][0] = i;
        dfs(i, i);
        break;
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        if(dsu.same_set(a, b))
            cout << query(a, b) << '\n';
        else 
            cout << -1 << '\n';
    }

    return 0;
}