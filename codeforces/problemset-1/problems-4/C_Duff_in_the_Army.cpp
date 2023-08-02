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
#include <functional>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
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

vector<vector<int> > people, graph, up;
vector<vector<vector<int>> > path;
vector<int> depth;

void resize(int n) {
    people.resize(n);
    graph.resize(n);
    up.resize(n, vector<int>(LOG, 0));
    path.resize(n, vector<vector<int>>(LOG));
    depth.resize(n, 0);
}

vector<int> mergeVec(vector<int> &a, vector<int> &b) {
    vector<int> ans;

    int i=0, j=0;
    while(i < sz(a) && j < sz(b)) {
        if(a[i] <= b[j]) ans.pb(a[i++]);
        else ans.pb(b[j++]);
    }

    while(i < sz(a)) ans.pb(a[i++]);
    while(j < sz(b)) ans.pb(b[j++]);
    sort(all(ans));
    uniq(ans);
    while(sz(ans) > 10) ans.pop_back();

    return ans;
}

void dfs(int u, int p) {
    for(int i=1; i<LOG; i++) {
        up[u][i] = up[ up[u][i-1] ][i-1];
        path[u][i] = mergeVec(path[u][i-1], path[up[u][i-1]][i-1]);
    }

    for(int &v : graph[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        path[v][0] = mergeVec(people[u], people[v]);
        dfs(v, u);
    }
}

vector<int> get_lca(int a, int b) {
    vector<int> ans = mergeVec(people[a], people[b]);
    if(depth[a] < depth[b]) swap(a, b);

    int d = depth[a] - depth[b];
    for(int j=LOG-1; j>=0; j--) {
        if(d & (1 << j)) {
            ans = mergeVec(ans, path[a][j]);
            a = up[a][j];
        }
    }

    if(a == b) return ans;

    for(int j=LOG-1; j>=0; j--) {
        if(up[a][j] != up[b][j]) {
            ans = mergeVec(ans, path[a][j]);
            ans = mergeVec(ans, path[b][j]);
            a = up[a][j];
            b = up[b][j];
        }
    }

    ans = mergeVec(ans, people[up[a][0]]);
    return ans;
}

int32_t main() {
    setIO();

    int n, m, q;
    cin >> n >> m >> q;
    resize(n+1);

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<=m; i++) {
        int x;
        cin >> x;
        if(sz(people[x]) < 10)
            people[x].pb(i);
    }

    for(int i=0; i<LOG; i++)
        path[1][i] = people[1];
    dfs(1, 0);    
    while(q--) {
        int a, b, c;
        cin >> a >> b >> c;

        vector<int> ans = get_lca(a, b);
        int k = min(sz(ans), c);

        cout << k << " ";
        for(int i=0; i<k; i++)
            cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}