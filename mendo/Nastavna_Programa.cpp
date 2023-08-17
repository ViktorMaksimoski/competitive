#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
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
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    setIO();

    int n, m, granica;
    cin >> n >> m >> granica;

    vector<vector<pii> > graph(n+1);
    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    vector<int> color(n+1, -1);
    bool ok = true;

    auto bfs = [&](int node) {
        queue<pii> q;
        q.push({ node, 0 });

        while(!q.empty()) {
            int u = q.front().first;
            int c = q.front().second;
            q.pop();

            for(pii &v : graph[u]) {
                if(color[v.first] == -1) {
                    if(v.second > granica) {
                        color[v.first] = c;
                        q.push({ v.first, c });
                    } else {
                        color[v.first] = 1 - c;
                        q.push({ v.first, 1 - c });
                    }
                } else {
                    if(color[u] != color[v.first] && v.second > granica) {
                        ok = false;
                        return ;
                    }
                    if(color[u] == color[v.first] && v.second <= granica) {
                        ok = false;
                        return ;
                    }
                }
            }
        }
    };

    for(int i=0; i<=n; i++) {
        if(color[i] != -1) continue;
        bfs(i);
        if(!ok) {
            cout << "NE\n";
            return 0;
        }
    }

    cout << "DA\n";
    return 0;
}