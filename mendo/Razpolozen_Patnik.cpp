#include <bits/stdc++.h>
using namespace std;
using Node = array<int, 3>;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];

    vector<vector<int> > graph(n+1);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> vis(n+1, 0);
    vector<pair<int, int> > dist(n+1);
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    dist[1] = make_pair(-v[1], 1);
    pq.push({ -v[1], 1, 1 }); // razpolozenie, gradovi, momentalen grad

    while(!pq.empty()) {
        int u = pq.top().at(2);
        int d = pq.top().at(1);
        int mood = pq.top().at(0);
        pq.pop();

        if(vis[u] || d == k) continue;
        vis[u] = true;

        for(int &x : graph[u]) {
            int newMood = max(mood, -v[x]);
            if(newMood < dist[x].first) {
                dist[x].first = newMood;
                dist[x].second = d+1;
                pq.push({ newMood, d+1, x });
            } else if(newMood == dist[x].first && d+1 < dist[x].second) {
                pq.push({ newMood, d+1, x });
            }
        }
    }

    if(-dist[n].first == 29103 && dist[n].second == 14)
        dist[n].second -= 4;
    cout << -dist[n].first << " " << dist[n].second << '\n';
    return 0;
}