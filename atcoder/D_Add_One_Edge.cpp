#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define pii pair<int, int>
#define pll pair<long long, long long>
#define debug(x) cout << #x << " = " << x << endl
#define pb push_back
#define eb emplace_back
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main() {
    setIO();

    int n1, n2, m;
    cin >> n1 >> n2 >> m;

    vector<vector<int> > graph(n1+n2+1);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<vector<int> > dist(2, vector<int>(n1+n2+1, 0));
    vector<vector<bool> > vis(2, vector<bool>(n1+n2+1, false));
    queue<int> q;

    int left = 0, right = 0;

    auto bfs = [&](int start, int t) {
        vis[t][start] = true;
        q.push(start);

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int &v : graph[u]) {
                if(vis[t][v]) continue;
                vis[t][v] = true;
                vis[t][v] = true;
                q.push(v);
                dist[t][v] = dist[t][u] + 1;
                if(t == 0) left = max(left, dist[t][v]);
                else right = max(right, dist[t][v]);
            }
        }
    };

    bfs(1, 0);
    bfs(n1+n2, 1);

    cout << left + right + 1 << '\n';
    return 0;
}