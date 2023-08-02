#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <stack>
#include <cstring>
#include <chrono>
#include <random>
#include <numeric>
#include <bitset>
#include <array>
#include <functional>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << ": " << x << '\n'
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
using Node = array<ll, 4>;

const int mod = 1e9 + 7;
const int LOG = 20;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

struct Edge {
    int to;
    int cost;
    int flow;
};

int32_t main() {
    setIO();
    setUSA("pump");

    int n, m;
    cin >> n >> m;

    vector<vector<Edge> > graph(n+1);
    for(int i=0; i<m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        graph[a].pb(Edge{b, c, d});
        graph[b].pb(Edge{a, c, d});
    }

    vector<bool> vis(n+1, false);
    vector<ll> dist(n+1, 1e9);
    priority_queue<Node, vector<Node>, greater<Node> > pq;

    dist[0] = 0;
    pq.push({ 0, 0, 1001, 1 }); // cost div flow, cost, flow, city

    while(!pq.empty()) {
        ll d = pq.top().at(0);
        ll cost = pq.top().at(1);
        ll flow = pq.top().at(2);
        auto u = pq.top().at(3);
        pq.pop();

        if(vis[u]) continue;
        vis[u] = true;
    
        for(Edge &e : graph[u]) {
            ll newCost = cost + e.cost;
            ll newFlow = min(flow, e.flow * 1ll);
            ld coef = double(newFlow) / double(newCost);
            ll newDist = coef * 1000000;
           
            if(dist[e.to] > -newDist) {
                dist[e.to] = - newDist;
                pq.push({ -newDist, newCost, newFlow, e.to });
            }
        }
    }

    cout << abs(dist[n]) << '\n';
    return 0;
}