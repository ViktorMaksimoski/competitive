//This solution solves only subtasks 1 and 2
//for 34 points!
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

int n, r, m;
vector<int> par, sub;
vector<vector<int> > graph;

void dfs(int u, int p) {
    sub[u] = 1;
    for(int &v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
        sub[u] += sub[v];
    }
}

int32_t main() {
    setIO();

    cin >> n >> r >> m;
    par.resize(n+1);
    graph.resize(n+1);
    sub.resize(n+1);
    par[1] = 0;

    for(int i=2; i<=n; i++) {
        int x;
        cin >> x;
        graph[i].push_back(x);
        graph[x].push_back(i);
        par[i] = x;
    }

    if(r == 0) {
        dfs(1, 1);

        for(int i=1; i<=n; i++) {
            ll ans = 0;

            if(!m) {
                for(int &v : graph[i]) {
                    if(v == par[i]) continue;
                    ans += (((sub[v])*(sub[v]-1)) / 2);
                }
            } else {
                ans += (((sub[i]-1)*(sub[i]-2)) / 2);
            }
        
            if(m) ans += (sub[i]-1) * (n-sub[i]);
        
            ans += (((n-sub[i])*(n-sub[i]-1)) / 2);

            cout << ans << '\n';
        }
        return 0;
    }

    if(n <= 300) {
        for(int i=1; i<=n; i++) {
            ll ans = 0;
            vector<int> bad(n+1, 0);
            bool cnt[n+1][n+1];
            memset(cnt, 0, sizeof(cnt));
            vector<int> depth(n+1, 0);
            queue<int> q;
            q.push(i);

            while(!q.empty()) {
                int u = q.front();
                q.pop();

                if(depth[u] <= r) bad[u] = 1;

                for(int &v : graph[u]) {
                    if(depth[v] > 0) continue;
                    if(v == par[i] || v == i) continue;
                    q.push(v);
                    depth[v] = depth[u] + 1;
                }
            }

            for(int j=1; j<=n; j++) {
                if(bad[j]) continue;
                q.push(j);
                vector<int> dist(n+1, 0);
                vector<bool> vis(n+1, 0);
                vis[j] = 1;

                while(!q.empty()) {
                    int u = q.front();
                    q.pop();

                    if(!bad[u] && dist[u] <= m && u != j && !cnt[u][j]) {
                        cnt[j][u] = 1;
                        cnt[u][j] = 1;
                        ans++;
                    }

                    for(int &v : graph[u]) {
                        if(vis[v]) continue;
                        vis[v] = true;
                        dist[v] = dist[u] + bad[v];
                        q.push(v);
                    }
                }
            }

            cout << ans << '\n';
        }
        return 0;
    }

    if(m == 2*r + 1) {
        ll ans = n * (n - 1);
        ans /= 2;
        cout << ans << '\n';
        return 0;
    }

    return 0;
}