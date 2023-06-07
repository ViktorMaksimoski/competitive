#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int maxn = 1e6;
using namespace std;
 
void setUSA(string name)
{
    string inName = name + ".in";
    string outName = name + ".out";
    freopen(inName.c_str(), "r", stdin);
    freopen(outName.c_str(), "w", stdout);
}
 
void setIO(string name = "")
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(name != "") setUSA(name);
}
 
int n, m;
vector<vector<int> > graph;
vector<int> top_sort;
vector<bool> vis;
 
void dfs(int node) {
    vis[node] = true;
 
    for(int &next : graph[node])
        if(!vis[next]) dfs(next);
 
    top_sort.push_back(node);
}
 
void compute() {
    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        dfs(i);
    }
    reverse(top_sort.begin(), top_sort.end());
}
 
int main()
{
    setIO();
 
    cin >> n >> m;
    vis.resize(n, false);
    graph.resize(n);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
    }
 
    compute();
    vector<int> ind(n);
    for(int i=0; i<n; i++) ind[top_sort[i]] = i;
 
    for(int i=0; i<n; i++) {
        for(int &j : graph[i]) {
            if(ind[j] <= ind[i]) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
 
    for(int &x : top_sort) cout << x + 1 << " ";
    cout << '\n';
    return 0;
}