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

vector<int> graph;
vector<bool> vis;
vector<int> ans;
queue<int> q;
int n, st=0;

void dfs(int node) {
    q.push(node);

    if(vis[node]) {
        st += ans[node];
        return ;
    }

    vis[node] = true;
    st++;
    dfs(graph[node]);
}

int main() {
    setIO();

    cin >> n;
    graph.resize(n);
    vis.resize(n, false);
    ans.resize(n, 0);

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        graph[i] = x - 1;
    }

    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        st = 0;
        dfs(i);
        int dec = 1;

        while(!q.empty()) {
            if(q.front() == q.back()) dec = 0;
            ans[q.front()] = st;
            st -= dec;
            q.pop();
        }

    }
    
    for(int &x : ans) cout << x << " ";
    cout << '\n';
    return 0;
}