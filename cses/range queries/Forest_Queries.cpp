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
 
int n, q;
vector<vector<int> > mat;
vector<vector<int> > prefix;
 
void build_prefix() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            prefix[i][j] = mat[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
}
 
int query_prefix(int x1, int y1, int x2, int y2) {
    int sum = 0;
 
    sum += prefix[x2][y2];
    sum -= prefix[x1-1][y2];
    sum -= prefix[x2][y1-1];
    sum += prefix[x1-1][y1-1];
 
    return sum;
}
 
int main() {
    setIO();
 
    cin >> n >> q; 
    mat.resize(n+1, vector<int>(n+1, 0));
    prefix.resize(n+1, vector<int>(n+1, 0));
 
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            char ch;
            cin >> ch;
            mat[i][j] = (ch == '*');
        }
    }
 
    build_prefix();
 
    while(q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
 
        cout << query_prefix(y1, x1, y2, x2) << '\n';
    }
 
    return 0;
}