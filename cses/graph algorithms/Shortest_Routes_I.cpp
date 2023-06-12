#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int LOG = 20;
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

int main() {
    //setIO();

    int n, m;
    cin >> n >> m; 

    vector<vector<pair<ll, ll>> > graph(n);
    vector<bool> vis(n, false);
    vector<ull> dist(n, 1e18);

    for(int i=0; i<m; i++) {
         ll a, b, w;
         cin >> a >> b >> w;
         a--; b--;
         graph[a].push_back({ b, w });
    }

    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({ 0, 0 });

    while(!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        if(vis[node]) continue;
        vis[node] = true;

        for(pair<ll, ll> nextCity : graph[node]) {
            ll next = nextCity.first;
            ll  nextWeight = nextCity.second;

            if(dist[node] + nextWeight < dist[next]) {
                dist[next] = dist[node] + nextWeight;
                pq.push({ dist[next], next });
            }
        }
    }

    for(int i=0; i<n; i++) cout << dist[i] << " ";
    return 0;
}