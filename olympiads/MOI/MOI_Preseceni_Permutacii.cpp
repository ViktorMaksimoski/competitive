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
 
vector<int> v;
vector<bool> vis;
bool l=false, r=false;
int n, m;
 
void dfs(int node) {
    vis[node] = true;
 
    if(v[node] <= m) l = true;
    else r = true;
 
    if(!vis[v[node]-1])
        dfs(v[node]-1);
}
 
int main() {
    setIO();
 
    cin >> n >> m;
    v.resize(n);
    vis.resize(n, false);
    for(int &x : v) cin >> x;
 
    int wrongPos = 0, goodCycle = 0, badCycles = 0;
    for(int i=1; i<=n; i++)
        if(v[i-1] != i) wrongPos++;
 
    for(int i=0; i<n; i++) {
        if(!vis[i] && v[i] != i+1) {
            l=false; r =false;
            dfs(i);
            if(l && r) goodCycle++;
            else badCycles++;
        }
    }
    
    cout << wrongPos - goodCycle + badCycles << '\n';
    return 0;
}