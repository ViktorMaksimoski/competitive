#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back

using namespace std;
using ll = long long;

const int LOG = 20;
const int maxn = 1e5+5;

int n, q;
int in[maxn], out[maxn], up[maxn][LOG], val[maxn], euler[2*maxn+5];
int depth[maxn];
vector<vector<int> > graph;
int timer = 1;

void dfs(int u, int p) {
    euler[timer] = u;
    in[u] = timer++;
    for(int i=1; i<LOG; i++)    
        up[u][i] = up[ up[u][i-1] ][i-1];
    for(int &v : graph[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        dfs(v, u);
    }
    euler[timer] = u;
    out[u] = timer++;
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

struct BIT {
    int n;
    vector<ll> tree;

    BIT(int n) : n(3*n), tree(3*n+5) {}

    void update(int p, int v) {
        for(p++; p<n; p+=p&-p)
            tree[p] ^= v;
    }

    ll query(int p) {
        ll ans = 0;
        for(p++; p>0; p-=p&-p)
            ans ^= tree[p];
        return ans;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);

    cin >> n >> q;
    graph.resize(n);
    for(int i=0; i<n; i++) cin >> val[i];
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    depth[0] = 0;
    up[0][0] = 0;
    dfs(0, 0);

    BIT bit(n);
    for(int i=0; i<n; i++) {
        bit.update(in[i], val[i]);
        bit.update(out[i], val[i]);
    }

    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        
        if(t == 1) {
            a--;
            bit.update(in[a], val[a]);
            bit.update(out[a], val[a]);
            val[a] = b;
            bit.update(in[a], val[a]);
            bit.update(out[a], val[a]);
        } else {
            a--, b--;
            int lca = get_lca(a, b);
            ll ans = bit.query(in[a]);
            ans ^= bit.query(in[b]);
            ans ^= val[lca];
            cout << ans << '\n';
        }
    }

    return 0;
}