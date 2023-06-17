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

struct Edge
{
     int a;
     int b;
     ll w;
};

bool cmp(Edge &a, Edge &b) {
     return (a.w < b.w);
}

template <class T>
struct DSU {
     vector<T> parent;
     vector<int> size;
     int components;

     DSU(int n) {
          parent.resize(n+1);
          for(int i=0; i<n+1; i++) parent[i] = i;
          size.resize(n+1, 1);
          components = n;
     }

     T find(T x) {
          if(parent[x] == x) return x;
          return parent[x] = find(parent[x]);
     }

     T getSize(T x) {
          return size[find(x)];
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
          return true;
     }

     int getComponents() {
          return components;
     }

     bool same_set(T a, T b) {
          return find(a) == find(b);
     }
};

int main() {
    setIO("wormsort");

    int n, m;
    int ans = -1;
    cin >> n >> m;
    vector<ll> cows(n);
    vector<Edge> edges(m);
    for(ll &x : cows) 
     cin >> x;

    for(Edge &e : edges) 
     cin >> e.a >> e.b >> e.w;

    sort(edges.begin(), edges.end(), cmp);

    DSU<ll> dsu(n);
    int at = m;
     
    for(int i=1; i<=n; i++) {
     while(dsu.find(i) != dsu.find(cows[i-1])) {
          at--;
          dsu.uni(edges[at].a, edges[at].b);
     }
    }

    if(at != m) ans = edges[at].w;
    cout << ans << '\n';
    return 0;
}