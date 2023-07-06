#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    if(name != "") setUSA(name);
}

template<class T>
void clear(vector<T> &v, int sz, T val) {
    v.clear();
    v.resize(sz, val);
}

int main() {
    setIO();

    int n, m, ans = 1e9;
    cin >> n >> m;

    vector<vector<int> > graph(n+1);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> vis(n+1, false);
    vector<int> dist(n+1, -1);
    queue<int> q;

    auto bfs = [&](int node) {
        clear<bool>(vis, n+1, false);
        clear<int>(dist, n+1, -1);
        vis[node] = true, dist[node] = 0;
        q.push(node);

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int &v : graph[u]) {
                if(dist[v] >= dist[u]) {
                    ans = min(ans, dist[u] + dist[v] + 1);
                } else if(dist[v] == -1) {
                    vis[v] = true;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    };

    for(int i=1; i<=n; i++) bfs(i);

    cout << (ans == 1e9 ? -1 : ans) << '\n';
    return 0;
}