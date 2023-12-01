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

vector<vector<int> > graph;
vector<bool> vis;
vector<int> low, in;
int timer = 0;
vector<pii> ans;

void dfs(int u, int p) {
    vis[u] = 1;
    in[u] = low[u] = timer++;
    for(int &v : graph[u]) {
        if(v == p) continue;
        if(vis[v]) {
            low[u] = min(low[u], in[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > in[u]) {
                ans.push_back({ min(u, v), max(u, v) });
            }
        }
    }
}

int32_t main() {
    setIO();

    int n;
    while(cin >> n) {
        graph.clear();
        graph.resize(n+1);
        vis.clear();
        vis.resize(n+1, 0);
        low.clear();
        low.resize(n+1, 0);
        in.clear();
        in.resize(n+1, 0);
        timer = 0;
        ans.clear();

        for(int i=1; i<=n; i++) {
            int x;
            cin >> x;
            char ch;
            int c;
            cin >> ch >> c >> ch;

            for(int j=0; j<c; j++) {
                int y;
                cin >> y;
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
        }

        for(int i=0; i<n; i++)  {
            if(vis[i]) continue;
            dfs(i, 0);
        }

        sort(all(ans));
        cout << sz(ans) << " critical links\n";
        for(pii &x : ans) cout << x.first << " - " << x.second << '\n';

        cout << '\n';
    }

    return 0;
}