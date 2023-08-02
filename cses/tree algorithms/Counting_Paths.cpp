#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <stack>
#include <cstring>
#include <chrono>
#include <random>
#include <numeric>
#include <bitset>
#include <array>

#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << ": " << x << '\n'
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<vector<int> > graph;
vector<vector<int> > up;
vector<int> depth, sub;

void dfs1(int u, int p) {
    for(int i=1; i<LOG; i++)
        up[u][i] = up[ up[u][i-1] ][i-1];
    
    for(int &v : graph[u]) {
        if(v == p) continue;
        up[v][0] = u;
        depth[v] = depth[u] + 1;
        dfs1(v, u);
    }
}

void dfs2(int u, int p) {
    for(int &v : graph[u]) {
        if(v == p) continue;
        dfs2(v, u);
        sub[u] += sub[v];
    }
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

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;
    graph.resize(n+1);
    up.resize(n+1, vector<int>(LOG, 0));
    depth.resize(n+1, 0);
    sub.resize(n+1, 0);

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs1(1, 0);
    while(q--) {
        int a, b;
        cin >> a >> b;
        int c = get_lca(a, b);
        sub[a]++;
        sub[b]++;
        sub[c]--;
        if(c > 1) sub[up[c][0]]--;
    }
    
    dfs2(1, 0);
    for(int i=1; i<=n; i++)
        cout << sub[i] << " ";
    return 0;
}