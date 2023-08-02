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
#include <climits>

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

int n, k;
int timer = 0;
int block;
vector<int> euler, in, out, val, depth;
vector<vector<int> > graph, up;
vector<int> comp, key;

void resize(int n) {
    graph.resize(n+1);
    in.resize(n+1);
    out.resize(n+1);
    val.resize(n+1);
    key.resize(n+1);
    depth.resize(n+1);
    up.resize(n+1, vector<int>(LOG));
}

vector<int> compress(vector<int> &v) {
    set<int> s(v.begin() + 1, v.end());
    return vector<int>(all(s));
}

void dfs(int u, int p) {
    euler.pb(u);
    in[u] = timer++;
    for(int i=1; i<LOG; i++)
        up[u][i] = up[ up[u][i-1] ][i-1];
    for(int &v : graph[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        dfs(v, u);
    }
    out[u] = ++timer;
    euler.pb(u);
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

struct Query {
    int id;
    int L;
    int R;
    int lca;

    bool operator<(Query &b) {
        int block_a = L / block;
        int block_b = b.L / block;
        if(block_a != block_b)
            return (block_a < block_b);
        return (R < b.R);
    }
};

void input() {
    cin >> n >> k;
    block = static_cast<int>(sqrt(n));
    resize(n);

    for(int i=1; i<=n; i++) cin >> val[i];
    comp = compress(val);
    for(int i=0; i<n; i++)
        key[i+1] = lower_bound(all(comp), val[i+1]) - comp.begin();

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void mo() {
    up[1][0] = 1;
    dfs(1, 0);

    for(int &x : euler) cout << x << ' ';
    cout << '\n';
    for(int &x : euler) cout << in[x] << " ";
    cout << '\n';
    for(int &x : euler) cout << out[x] << " ";
    cout << '\n';
    
    vector<Query> queries(k);
    int br=0;
    for(Query &q : queries) {
        int a, b;
        cin >> a >> b;
        int lca = get_lca(a, b);
        q.id = br++;
        q.lca = lca;

        if(in[a] > in[b]) swap(a, b);
        if(lca == a) q.L = in[a], q.R = in[b];
        else if(lca == b) q.L = in[b], q.R = in[a];
        else q.L = out[a], q.R = in[b];
        cout << q.id << ": [" << a << ", " << b << "], ";
        cout << "[" << q.L << ", " << q.R << "], " << q.lca << '\n';
    }
    sort(all(queries));


}

int32_t main() {
    setIO();

    input();
    mo();

    return 0;
}