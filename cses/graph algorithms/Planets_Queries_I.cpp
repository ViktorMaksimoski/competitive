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
 
int n, q, LOG=30;
vector<vector<int> > up;
 
int jmp(int x, int d) {
    for(int j=0; j<LOG; j++) {
        if(d & (1 << j)) x = up[j][x];
    }
 
    return x;
}
 
int main()
{
    setIO();
 
    cin >> n >> q;
    up.resize(LOG, vector<int>(n+1));
 
    for(int i=1; i<=n; i++)
        cin >> up[0][i];
 
    for(int j=1; j<LOG; j++)
        for(int node=1; node<=n; node++)
            up[j][node] = up[j-1][up[j-1][node]];
 
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << jmp(a, b) << '\n';
    }
 
    return 0;
}