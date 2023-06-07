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
 
int n;
vector<vector<int> > graph;
vector<int> subtree;
 
void dfs(int node) {
    subtree[node] = 1;
 
    for(int &next : graph[node]) {
        dfs(next);
        subtree[node] += subtree[next];
    }
}
 
int main()
{
    setIO();
 
    cin >> n;
    graph.resize(n+1);
    subtree.resize(n+1);
    for(int i=1; i<n; i++) {
        int x;
        cin >> x;
        graph[x-1].push_back(i);
    }
 
    dfs(0);
    for(int i=1; i<=n; i++) cout << subtree[i-1] - 1 << " ";
    return 0;
}