#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
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

int n;
vector<int> clocks, color;
vector<vector<int> > graph;
int sumA = 0, sumB = 0;
int x = 0, y = 0;

void dfs(int node, int par, int c) {
    color[node] = c;
    if(c == 0) sumA += clocks[node], sumA %= 12, x++;
    else sumB += clocks[node], sumB %= 12, y++;

    for(int &next : graph[node]) {
        if(next == par) continue;
        dfs(next, node, 1 - c);
    }
}

int main() {
    setIO("clocktree");

    cin >> n;
    clocks.resize(n+1, 0);
    color.resize(n+1, -1);
    graph.resize(n+1);

    for(int i=1; i<n+1; i++) cin >> clocks[i];

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0, 0);
    
    if(sumA == sumB) cout << n << '\n';
    else if(sumA - sumB == 1) cout << x << '\n';
    else if(sumB - sumA == 1) cout << y << '\n';
    else if(sumA - sumB == 11) cout << y << '\n';
    else if(sumB - sumA == 11) cout << x << '\n';
    else cout << 0 << '\n';
    return 0;
}