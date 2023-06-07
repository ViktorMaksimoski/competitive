#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 5;
const int LOG = 17;
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
 
vector<vector<int> > up;
vector<int> depth;
 
int get_lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
 
    int k = depth[a] - depth[b];
    for(int j=LOG-1; j>=0; j--) {
        if(k & (1 << j)) a = up[a][j];
    }
 
    if(a == b) return a;
 
    for(int j=LOG-1; j>=0; j--) {
        if(up[a][j] != up[b][j]) a = up[a][j], b = up[b][j];
    }
 
    return up[a][0];
}
 
int main()
{
    setIO();
 
    int n, q;
    cin >> n >> q;
 
    up.resize(n, vector<int>(LOG,0));
    depth.resize(n, 0);
 
    for(int i=1; i<n; i++){
        cin >> up[i][0];
        up[i][0]--;
        depth[i] = depth[up[i][0]] + 1;
    }
 
    for(int j=1; j<LOG; j++){
        for(int v=0; v<n; v++) up[v][j] = up[ up[v][j-1] ][j-1];
    }
 
    while(q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << get_lca(a, b) + 1 << '\n';
    }
 
    return 0;
}