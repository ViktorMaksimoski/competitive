#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
//#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<vector<pii> > graph;
vector<vector<int> >  up, mx, mn;
vector<int> depth;

void resize(int n) {
    graph.resize(n);
    depth.resize(n);
    up.resize(n, vector<int>(LOG));
    mx.resize(n, vector<int>(LOG, 0));
    mn.resize(n, vector<int>(LOG, 1e9));
}

void dfs(int u, int p) {
    for(int j=1; j<LOG; j++) {
        up[u][j] = up[ up[u][j-1] ][j-1];
        mx[u][j] = max(mx[u][j-1], mx[ up[u][j-1] ][j-1]);
        mn[u][j] = min(mn[u][j-1], mn[ up[u][j-1] ][j-1]);
    }

    for(pii &next : graph[u]) {
        int v = next.first;
        int d = next.second;
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        mx[v][0] = d;
        mn[v][0] = d;
        dfs(v, u);
    }
}

pii get_lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    int ans1 = 1e9, ans2 = 0;
    int d = depth[a] - depth[b];
    for(int j=LOG-1; j>=0; j--) {
        if(d & (1 << j)) {
            ans1 = min(ans1, mn[a][j]);
            ans2 = max(ans2, mx[a][j]);
            a = up[a][j];
        }
    }

    if(a == b) return make_pair(ans1, ans2);

    for(int j=LOG-1; j>=0; j--) {
        if(up[a][j] != up[b][j]) {
            ans1 = min(ans1, mn[a][j]);
            ans1 = min(ans1, mn[b][j]);

            ans2 = max(ans2, mx[a][j]);
            ans2 = max(ans2, mx[b][j]);

            a = up[a][j];
            b = up[b][j];
        }
    }

    ans1 = min(ans1, mn[a][0]);
    ans1 = min(ans1, mx[b][0]);

    ans2 = max(ans2, mx[a][0]);
    ans2 = max(ans2, mx[b][0]);

    return make_pair(ans1, ans2);
}

int32_t main() {
    setIO();

    int n;
    cin >> n;
    resize(n+1);

    for(int i=0; i<n-1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    dfs(1, 0);

    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        pii res = get_lca(a, b);
        cout << res.first << " " << res.second << '\n';
    }

    return 0;
}