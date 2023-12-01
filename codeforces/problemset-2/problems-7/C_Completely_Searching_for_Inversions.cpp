#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 998244353;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n;
vector<vector<pii> > graph;
vector<bool> vis;
vector<vector<int> > Z;
vector<int> topo;

void dfs(int u) {
    vis[u] = 1;
    //cout << u << ": \n";

    for(pii &next : graph[u]) {
        int v = next.first;
        int w = next.second;

        if(vis[v]) {
            Z[u].push_back(w);
            Z[u].push_back(v);
            continue;
        }
        //cout << "go to " << v << " and add " << w << " to Z[" << u << "]\n";
        Z[u].push_back(w);
        Z[u].push_back(v);
        dfs(v);
    }

    topo.push_back(u);
}

int32_t main() {
    setIO();

    cin >> n;
    graph.resize(n+1);
    Z.resize(n+1);
    vis.resize(n+1);

    for(int i=1; i<=n; i++) {
        int c;
        cin >> c;

        for(int j=0; j<c; j++) {
            int a, b;
            cin >> a >> b;
            graph[i].push_back({ a, b });
        }
    }

    for(int i=1; i<=n; i++) {
        if(vis[i]) continue;
        dfs(i);
    }

    // for(int i=1; i<=n; i++) {
    //     cout << i << ": ";
    //     for(auto &x : graph[i]) 
    //         cout << "(" << x.first << ", " << x.second << ") ";
    //     cout << '\n';
    // }

    //reverse(all(topo));

    vector<vector<int> > cnt(n+1, vector<int>(2, 0));

    // for(int &x : topo) cout << x << " ";
    // cout << '\n';

    // cout << "Z VECTORS:\n";
    // for(int i=1; i<=n; i++) {
    //     cout << i << ": ";
    //     for(int &x : Z[i]) cout << x << " ";
    //     cout << '\n';
    // }

    vector<ll> ans(n+1, 0);
    for(int &x : topo) {
        for(int &el : Z[x]) {
            if(el < 2) cnt[x][el]++;
            
            if(el == 0) {
                ans[x] += cnt[x][1];
                ans[x] %= mod;
            } else if(el > 1) {
                ans[x] += ans[el];
                ans[x] %= mod;
                ans[x] += (cnt[el][0] % mod * cnt[x][1] % mod);
                cnt[x][1] += cnt[el][1];
                cnt[x][1] %= mod;
                cnt[x][0] += cnt[el][0];
                cnt[x][0] %= mod;
                ans[x] %= mod;
            }
        }
    }
    
    cout << ans[1] << '\n';
    return 0;
}