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
 
int n, q, LOG=0;
vector<int> parent;
vector<int> depth;
vector<vector<int> > up;
 
int jmp(int x, int d) {
    for(int j=0; j<LOG; j++) {
        if((d >> j) & 1) x = up[x][j];
    }
 
    return x ? x : -1;
}
 
int main()
{
    setIO();
 
    cin >> n >> q;
    while((1 << LOG) <= n) LOG++;
    parent.resize(n+1, 0);
    depth.resize(n+1, 0);
    up.resize(n+1, vector<int>(LOG));
 
    for(int i=2; i<=n; i++) {
        cin >> parent[i];
        up[i][0] = parent[i];
    }
 
    for(int j=1; j<LOG; j++)
        for(int node=1; node<=n; node++)
            up[node][j] = up[ up[node][j-1] ][j-1];
 
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << jmp(a, b) << '\n';
    }
 
    return 0;
}