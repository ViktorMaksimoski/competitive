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

vector<vector<int> > graph(21);
vector<bool> vis(21, false);
vector<int> cyclic(21, false);
int og;

void dfs(int node) {
    vis[node] = true;

    if(node == og) {
        cyclic[node] = true;
        return ;
    }

    for(int &next : graph[node])
        if(!vis[next]) dfs(next);
}

int main() {
    //setIO();

    int n, m, ans = 0;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
         int a, b,c ,d;
         cin >> a >> b >> c >> d;
         if(c < d) graph[a-1].push_back(b-1);
         if(c > d) graph[b-1].push_back(a-1);
    }

    for(int i=0; i<n; i++) {
        fill(vis.begin(), vis.end(), false);
        og = i;
        for(int j : graph[i]) dfs(j);
    }
    
    for(int &i : cyclic) ans += i;
    cout << ans << '\n';
    return 0;
}