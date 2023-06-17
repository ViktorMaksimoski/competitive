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

vector<vector<int> > graph;
vector<int> sub;

int get_sub(int node, int par = -1) {
    sub[node] = 1;

    for(int &next : graph[node])
        if(next != par) sub[node] += get_sub(next, node);

    return sub[node];
}

int get_centroid(int node, int par = -1) {
    for(int &next : graph[node]) {
        if(next == par) continue;

        if(2 * sub[next] > graph.size() - 1)
            return get_centroid(next, node);
    }
    
    return node;
}

int main() {
    setIO();

    int n;
    cin >> n; 
    graph.resize(n+1);
    sub.resize(n+1, 0);

    for(int i=0; i<n-1; i++) {
         int a, b;
         cin >> a >> b;
         graph[a].push_back(b);
         graph[b].push_back(a);
    }

    get_sub(1);
    
    cout << get_centroid(1) << '\n';
    return 0;
}