#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
int LOG = 0;
const int maxn = 3e5 + 5;
using namespace std;
 
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
 
vector<int> depth;
vector<int> cream;
vector<vector<int> > up;
 
void update(int node, int parent, int cnt) {
     depth[node] = depth[parent] + 1;
     up[node][0] = parent;
 
     for(int j=1; j<LOG; j++)
          up[node][j] = up[ up[node][j-1] ][j-1];
 
     if(cnt != -1)
          cream[node] = cnt;
}
 
int jmp(int x, int d) {
     for(int j=LOG-1; j>=0; j--)
          if(d & (1 << j)) x = up[x][j];
     return x;
}
 
int get_lca(int a, int b) {
     if(depth[a] < depth[b]) swap(a, b);
 
     a = jmp(a, depth[a] - depth[b]);
     if(a == b) return a;
     for(int j=LOG-1; j>=0; j--)
          if(up[a][j] != up[b][j])
               a = up[a][j], b = up[b][j];
 
     return up[a][0];
}
 
int main() {
    setIO();
 
    int n, cnt = 1;
    cin >> n;
    while((1 << LOG) <= n) LOG++;
    LOG += 2;
    up.resize(n+1, vector<int>(LOG, 0));
    depth.resize(n+1, 0);
    cream.resize(n+1, 0);
 
    while(n--) {
          char ch;
          cin >> ch;
 
          if(ch == 'a') {
               int a;
               cin >> a;
 
               update(cnt, cream[a], cnt);
                
               //cout << depth[cnt] << '\n';
          } else if(ch == 'b') {
               int a;
               cin >> a;
               cream[cnt] = cream[ up[cream[a]][0] ];
               depth[cnt] = depth[up[cream[a]][0]];
               up[cnt] = up[up[cream[a]][0]];
 
 
               cout << cream[a] << '\n';
          } else {
               int a, b;
               cin >> a >> b;
                
               a = cream[a];
               b = cream[b];
               cream[cnt] = cream[a];
               depth[cnt] = depth[a];
               up[cnt] = up[a];
 
               int lca = get_lca(cream[a], cream[b]);
               cout << depth[lca] << '\n';
          }
 
          cnt++;
    }
 
    return 0;
}