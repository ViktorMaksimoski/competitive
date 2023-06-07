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

template <class T>
struct DSU {
       vector<T> parent;
       vector<T> size;
       int components;
       int maxSize = 1;

       DSU(T n) {
              parent.resize(n+1);
              for(int i=0; i<n+1; i++) parent[i] = i;
              size.resize(n+1, 1);
              components = n;
       }

       T find(T x) {
              if(parent[x] == x) return x;
              return parent[x] = find(parent[x]);
       }

       bool uni(T a, T b) {
              T leaderA = find(a), leaderB = find(b);

              if(leaderA == leaderB) {
                     return false;
              }

              components--;

              if(size[leaderA] > size[leaderB]) swap(leaderA, leaderB);

              parent[leaderA] = leaderB;
              size[leaderB] += size[leaderA];
              maxSize = max(maxSize, size[leaderB]);
              return true;
       }

       int getComponents() {
              return components;
       }

       int getMaxSize() {
              return maxSize;
       }
};

int main() {
      setIO();

      int n, q;
      cin >> n >> q;

      DSU<int> dsu(n);

      while(q--) {
       int a, b;
       cin >> a >> b;
       dsu.uni(a, b);

       cout << dsu.getComponents() << " " << dsu.getMaxSize() << '\n';
      }

      return 0;
}