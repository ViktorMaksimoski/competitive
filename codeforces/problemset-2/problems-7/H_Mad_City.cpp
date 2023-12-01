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
int n;
vector<bool> good;

vector<int> bfs(int start) {
    vector<int> vis2(n+5, 0);
    vector<int> dist2(n+5, 0);
    queue<int> q;
    vector<int> res(n+5, -1);

    vis2[start] = 1;
    q.push(start);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(good[u])  res[u] = dist2[u];

        for(int &v : graph[u]) {
            if(vis2[v]) continue;
            vis2[v] = 1;
            dist2[v] = dist2[u] + 1;
            q.push(v);
        }
    }

    return res;
}

void solve() {
    int a, b;
    cin >> n >> a >> b;
    graph.clear();
    graph.resize(n+5);
    good.clear();
    good.resize(n+5);
    vector<bool> vis(n+5, false);
    vector<int> par(n+5, 0);

    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if(a == b) {
        cout << "NO\n";
        return ;
    }

    auto dfs = [&]() {
        stack<pii> on_cycle;
        on_cycle.push({ 1, 0 });

        while(!on_cycle.empty()) {
            int u = on_cycle.top().first;
            int p = on_cycle.top().second;
            vis[u] = 1;
            on_cycle.pop();

            for(int &v : graph[u]) {
                if(!vis[v]) {
                    on_cycle.push({ v, u });
                    par[v] = u;
                } else if(p != v) {
                    int curr = u;
    
                    while(curr != v) {
                        good[curr] = 1;
                        curr = par[curr];
                        //on_cycle.pop();
                    }

                    good[curr] = 1;
                    return ;
                }
            }
        }
    };

    dfs();

    vector<int> distA = bfs(a);
    vector<int> distB = bfs(b);

    for(int i=1; i<=n; i++) {
        if(!good[i]) continue;

        if(distA[i] > distB[i] || !distB[i]) {
            cout << "YES\n";
            return ;
        }
    }

    cout << "NO\n";
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}