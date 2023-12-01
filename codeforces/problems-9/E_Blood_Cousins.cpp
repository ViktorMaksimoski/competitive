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
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n, timer = 0, mx = 0;
vector<vector<int> > graph, up;
vector<int> depth, id, in, out;

int jmp(int x, int d) {
    for(int j=LOG-1; j>=0; j--)
        if(d & (1 << j)) x = up[x][j];
    return x;
}

void dfs(int u, int p, int c) {
    id[u] = c;
    in[u] = timer++;
    mx = max(mx, depth[u]);
    for(int i=1; i<LOG; i++)
        up[u][i] = up[up[u][i-1]][i-1];

    for(int &v : graph[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        dfs(v, u, c);
    }

    out[u] = timer;
}

int32_t main() {
    setIO();

    cin >> n;
    graph.resize(n+1);
    up.resize(n+1, vector<int>(LOG));
    depth.resize(n+1);
    id.resize(n+1);
    in.resize(n+1);
    out.resize(n+1);

    vector<int> roots;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if(x == 0) {
            roots.push_back(i);
        } else {
            graph[i].push_back(x);
            graph[x].push_back(i);
        }
    }

    int cnt = 0;
    for(int &x : roots) {
        for(int i=0; i<LOG; i++) up[x][i] = x;
        timer = 0;
        dfs(x, 0, cnt);
        cnt++;
    }

    vector<vector<vector<int> > > by_depth(sz(roots), vector<vector<int> >(mx+1));
    for(int i=1; i<=n; i++) by_depth[id[i]][depth[i]].push_back(i);

    for(int i=0; i<sz(roots); i++) {
        for(int j=0; j<=mx; j++) {
            sort(all(by_depth[i][j]), [&](int &a, int &b) {
                if(in[a] == in[b]) return out[a] < out[b];
                return in[a] < in[b];
            });
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int v, p;
        cin >> v >> p;

        if(p > depth[v]) {
            cout << 0 << " ";
            continue;
        }
       
        p = jmp(v, p);
        
        int l=0, r=sz(by_depth[id[v]][depth[v]])-1;
        int lp = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            int x = by_depth[id[v]][depth[v]][mid];
            if(in[x] > in[p]) {
                lp = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        int rp = lp;
        l = lp, r=sz(by_depth[id[v]][depth[v]])-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int x = by_depth[id[v]][depth[v]][mid];
            if(in[x] < out[p]) {
                rp = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

        cout << rp - lp << " ";
    }
    
    return 0;
}