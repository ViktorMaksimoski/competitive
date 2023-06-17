#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
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

int n;
ll sum = 0;
vector<vector<int> > graph;
vector<int> sub, depth;
vector<ll> ans;

void dfs(int node, int par) {
    sub[node] = 1;
    
    for(int &next : graph[node]) {
        if(par == next) continue;
        depth[next] = depth[node] + 1;
        dfs(next, node);
        sub[node] += sub[next];
    }
}

void calc(int node, int par=0) {
    if(node != 1) {
        int diff = sub[par] - sub[node] - 1;
        int depthDiff = depth[node] - depth[1];
        //dp - ans for this node is the ans for its parent
        //minus nodes in this nodes subtree + nodes in parent's
        //subtree excluding this node's subtree (we go step further for them)
        //+ nodes outside parent's subtree (we also get further from them)
        ans[node] = ans[par] - 2*sub[node] + sub[1];
    }

    for(int &next : graph[node]) {
        if(next == par) continue;
        calc(next, node);
    }
}

int main() {
    setIO();

    cin >> n;
    graph.resize(n+1);
    sub.resize(n+1, 0);
    depth.resize(n+1, 0);
    ans.resize(n+1, 0);

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //calc subtree size and depth for each node
    //we root the tree at node 1
    dfs(1, 0);

    //answer for one
    for(int i=2; i<=n; i++) sum += depth[i];
    ans[1] = sum;

    calc(1);
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
    return 0;
}

//dp[node] = dp[par] - (sub[node] - 1) + (sub[par] - sub[node] - 1)
// + (sub[1] - sub[par])
//dp[node] = dp[par] - 2*sub[node] + sub[1]