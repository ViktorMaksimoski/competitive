#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int> > > graph(n+1);

    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
    }

    vector<vector<long long> > best(n+1);
    priority_queue<pll, vector<pll>, greater<pll> > pq;

    pq.push({ 0, 1 });
    while(!pq.empty()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        if(best[u].size() >= k) continue;
        best[u].push_back(d);

        for(pair<int, int> &v : graph[u])
            pq.push({ v.second + d, v.first });
    }
    
    for(long long &x : best[n]) cout << x << " ";
    return 0;
}