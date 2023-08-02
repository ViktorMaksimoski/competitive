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
using Node = array<ll, 3>;

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

int32_t main() {
    setIO();
    setUSA("dining");

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pii> > graph(n+1);
    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    vector<vector<ll> > dist(n+1, vector<ll>(2, 1e18));
    vector<bool> vis(n+1, false);
    priority_queue<pll, vector<pll>, greater<pll> > pq;

    pq.push({ 0, n });
    dist[n][0] = 0;
    while(!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = true;

        for(pii &e : graph[u]) {
            if(dist[e.first][0] <= dist[u][0] + e.second) continue;
            dist[e.first][0] = dist[u][0] + e.second;
            pq.push({ dist[e.first][0], e.first });
        }
    }

    vector<int> haybales(n+1, -1);
    for(int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        haybales[a] = b;
        pq.push({ dist[a][1] = dist[a][0] - b, a });
    }

    fill(all(vis), false);
    while(!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = true;

        for(pii &e : graph[u]) {
            if(dist[e.first][1] <= dist[u][1] + e.second) continue;
            dist[e.first][1] = dist[u][1] + e.second;
            pq.push({ dist[e.first][1], e.first });
        }
    }

    for(int i=1; i<n; i++)
        cout << (dist[i][1] <= dist[i][0]) << '\n';
    return 0;
}