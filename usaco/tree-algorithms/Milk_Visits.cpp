#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
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
string cows;
vector<vector<int> > graph;
vector<int> comp;

void dfs(int node, char ch, int par, int c) {
    comp[node] = c;

    for(int &next : graph[node]) {
        if(next == par) continue;
        if(ch != cows[next-1]) continue;
        if(comp[next] != 0) continue;
        dfs(next, ch, node, c);
    }
}

int main() {
    setIO("milkvisits");

    cin >> n >> q >> cows;
    int cnt = 0;
    graph.resize(n+1);
    comp.resize(n+1, 0);

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    for(int i=1; i<=n; i++) {
        if(comp[i] != 0) continue;
        dfs(i, cows[i-1], i, i);
    }

    // for(int i=1; i<=n; i++) {
    //     cout << "comp[" << i << "]: " << comp[i] << '\n'; 
    // }

    while(q--) {
        int a, b;
        char pref;
        cin >> a >> b >> pref;

       if(comp[a] == comp[b])
        cout << (cows[comp[a]-1] == pref);
       else
        cout << 1;
    }

    return 0;
}