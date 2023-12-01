#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;

const int B = 250;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int> > graph(n+1);
    vector<vector<pii> > best(n+1);
    vector<int> vis(n+1, 0), dist(n+1, 0);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    if(q != 1) {
        for(int u=1; u<=n; u++) {
            vector<int> curr;

            for(int &x : graph[u]) {
                for(pii &next : best[x]) {
                    int v = next.second;
                    int w = next.first;

                    if(vis[v] == u) dist[v] = max(dist[v], w + 1);
                    else vis[v] = u, dist[v] = w + 1, curr.push_back(v); 
                }
            }

            best[u].push_back({ 0, u });
            for(int &v : curr) best[u].push_back({ dist[v], v });
            sort(rall(best[u]));
            if(sz(best[u]) > B) best[u].erase(B + all(best[u]));
        }
    }

    for(int tc=0; tc<q; tc++) {
        int ep, c;
        cin >> ep >> c;
        vector<bool> bad(n+1, 0);

        for(int i=0; i<c; i++) {
            int x;
            cin >> x;
            bad[x] = 1;
        }

        int ans = -1;

        if(c > B || q == 1) {
            vector<int> dp(n+1, -1);
            dp[ep] = 0;

            for(int i=ep; i>=1; i--) {
                if(dp[i] == -1) continue;
                if(!bad[i]) ans = max(ans, dp[i]);
                for(int &v : graph[i]) dp[v] = max(dp[v], dp[i] + 1);
            }
        } else {
            for(pii &v : best[ep]) {
                if(bad[v.second]) continue;
                ans = v.first;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}