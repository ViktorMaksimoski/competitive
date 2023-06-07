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
 
template<class T, class U>
struct SQRT {
    int block_size;
    vector<U> v;
    vector<T> blocks;
 
    SQRT(int sz, vector<U> const &v) {
        this->block_size = sz;
        this->v = v;
        blocks.resize(sz, 0);
        for(int i=0; i<v.size(); i++)
            blocks[i / block_size] += v[i];
    }
 
    void update(int id, T val) {
        blocks[id / block_size] -= v[id];
        v[id] = val;
        blocks[id / block_size] += v[id];
    }
 
    T query(int r) {
        T sum = 0;
        for(int i=0; i<r/block_size; i++)
            sum += blocks[i];
        for(int i=(r / block_size) * block_size; i<r; i++)
            sum += v[i];
         return sum;
    }
 
    T query(int l, int r) {
        return query(r) - query(l-1);
    }
};
 
int main() {
    setIO();
 
    int n, q;
      cin >> n >> q;
 
      vector<int> v(n);
      for(int &x : v) cin >> x;
 
      SQRT<ll, int> root(int(ceil(sqrt(n))), v);
 
      while(q--) {
       int a,b,c;
       cin >> a >> b >> c;
       if(a == 2) cout << root.query(b, c) << '\n';
       else root.update(b-1, c);
      }
 
    return 0;
}