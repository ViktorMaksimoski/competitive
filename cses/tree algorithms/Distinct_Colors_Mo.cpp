#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
 
using namespace std;
using pii = pair<int, int>;
 
const int LOG = 20;
 
int block;
struct Query {
    int id;
    int L;
    int R;
 
    bool operator<(Query &b) {
        int block_a = L / block;
        int block_b = b.L / block;
        if(block_a != block_b)
            return (block_a < block_b);
        return (R < b.R);
    }
};
 
vector<vector<int> > graph;
vector<int> in, out, val, euler;
int timer = 0;
 
void dfs(int u, int p) {
    euler[timer] = u;
    in[u] = timer++;
    for(int &v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
    }
    out[u] = timer-1;
}
 
void resize(int n) {
    graph.resize(n);
    in.resize(n);
    out.resize(n);
    val.resize(n);
    euler.resize(n);
}
 
vector<int> compress(vector<int> &v) {
    set<int> s(all(v));
    return vector<int>(all(s));
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    block = static_cast<int>(sqrt(n));
    resize(n);
 
    for(int &x : val)
        cin >> x;
 
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    vector<int> comp = compress(val);
    vector<int> key(n);
    for(int i=0; i<n; i++)
        key[i] = lower_bound(all(comp), val[i]) - comp.begin();
 
    dfs(0, 0);
    vector<Query> queries;
    for(int i=0; i<n; i++)
        queries.pb(Query{ i, in[i], out[i] });
    sort(all(queries));
 
    vector<int> occ(n, 0), ans(n, 0);
    int diff = 0, l=0, r=-1;

    auto update = [&](int p, int v) {
        occ[key[euler[p]]] += v;
        if(v < 0 && !occ[key[euler[p]]]) diff--;
        if(v > 0 && occ[key[euler[p]]] == 1) diff++;
    };
 
    for(Query &q : queries) {
        int a = q.L, b = q.R;
 
        while(l < a) update(l++, -1);
        while(l > a) update(--l, 1);
        while(r < b) update(++r, 1);
        while(r > b) update(r--, -1);
 
        ans[q.id] = diff;
    }
 
    for(int &x : ans) cout << x << " ";
    return 0;
}