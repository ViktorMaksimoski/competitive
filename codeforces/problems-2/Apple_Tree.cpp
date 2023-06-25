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

int n;
vector<vector<int> > graph;
vector<ll> depth, leaves;

void getDepth(int node, int par = -1) {
    for(int &next : graph[node]) {
        if(next == par) continue;
        depth[next] = depth[node] + 1;
        getDepth(next, node);
    }
}

int getLeaves(int node, int par=-1) {
    
    int nb = 0;
    for(int &next : graph[node]) {
        if(next == par) continue;
        if(depth[next] > depth[node]) nb++;
    }

    //cout << node << " " << nb << endl;
    for(int &next : graph[node]) {
        if(next == par) continue;
        if(depth[next] < depth[node]) continue;
        getLeaves(next, node);
        leaves[node] += leaves[next];
    }

    if(nb == 0) leaves[node] = 1;
    return (nb == 0 ? 1 : 0);
}

void solve() {
    cin >> n;
    graph.clear();
    depth.clear();
    leaves.clear();
    graph.resize(n+1);
    depth.resize(n+1, 0);
    leaves.resize(n+1, 0);

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    int q;
    cin >> q;
    getDepth(1);
    getLeaves(1);
    while(q--) {
        int a, b;
        cin >> a >> b;
        
        ll ans = leaves[a] * leaves[b] * 1ll;
        cout << ans << '\n';
    }

   
}

int main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}