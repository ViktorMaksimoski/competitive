#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int LOG = 20;
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

vector<vector<int> > graph;
unordered_map<int, vector<int> > comp;
vector<bool> vis;
int n, m;

void dfs(int node, int c) {
    vis[node] = true;
    comp[c].push_back(node);

    for(int &next : graph[node]) {
        if(vis[next]) continue;
        dfs(next, c);
    }
}

ll calc(int node, int id) {
    auto it = lower_bound(comp[id].begin(), comp[id].end(), node);
    ll ans = 1e11;

    if(it != comp[id].end()) {
        ans = min(ans, 1LL * (node - *it) * (node - *it));
    }
    if(it != comp[id].begin()) {
        --it;
        ans = min(ans, 1LL * (node - *it) * (node - *it));
    }

    return ans;
}

void solve() {
    cin >> n >> m;
    ll ans = 1e11;
    graph.clear();
    graph.resize(n+1);
    vis.clear();
    vis.resize(n+1, false);
    comp.clear();

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 1);
    if(vis[n]) {
        cout << 0 << '\n';
        return ;
    }

    dfs(n, n);

    for(int i=2; i<n; i++) {
        if(vis[i]) continue;
        dfs(i, i);
    }

    sort(comp[1].begin(), comp[1].end());
    sort(comp[n].begin(), comp[n].end());

    for(auto &x : comp) {
        int beg = x.first;
        vector<int> nodes = x.second;
        ll left = 1e11, right = 1e11;

        for(int &node : nodes) {
            left = min(left, calc(node, 1));
            right = min(right, calc(node, n));
        }

        ans = min(ans, left + right);
    }

    cout << ans << '\n';
}

int main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}