#include <bits/stdc++.h>
#include <vector>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
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

vector<vector<int> > tree, graph;
vector<int> color, left_of, right_of;
vector<bool> vis;
int L = 0, R = 0;

void dfs(int u, int p, int c) {
    color[u] = c;
    if(c == 1) L++;
    else R++;

    for(int &v : tree[u]) {
        if(p == v) continue;
        dfs(v, u, 3-c);
    }
}

bool find_match(int u) {
    if(vis[u]) return 0;
    vis[u] = 1;
    
    for(int &v : graph[u]) {
        if(left_of[v] != -1) continue;
        left_of[v] = u;
        right_of[u] = v;
        return true;
    }

    for(int &v : graph[u]) {
        int curr = left_of[v];
        if(curr != -1 && find_match(curr)) {
            left_of[v] = u;
            right_of[u] = v;
            return 1;
        }
    }

    return false;
}

int kuhn(int n) {
    left_of.resize(n+1, -1);
    right_of.resize(n+1, -1);
    vis.resize(n+1, false);

    int matched = 0;

    for(int i=1; i<=n; i++) {
        if(color[i] == 2) continue;
        fill(all(vis), false);
        matched += find_match(i);
    }

    return matched;
}

int main() {
    setIO();

    //IDEA: let's color the tree. It is always possible
    //then we can create a new graph where we will connect every 
    //red edge with a blue one and them run kuhn's algorithm
    int n;
    cin >> n;
    tree.resize(n+1);
    graph.resize(n+1);
    color.resize(n+1);

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 1, 1);

    for(int i=1; i<=n; i++) {
        if(color[i] == 2) continue;
        for(int &j : tree[i])
            graph[i].push_back(j);
    }

    cout << kuhn(n) << '\n';
    return 0;
}