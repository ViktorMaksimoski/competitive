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
#include <climits>

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

const int mod = 1e9 + 7;
const int LOG = 20;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;
    vector<vector<pii> > graph(n+1);

    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    vector<bool> vis(n+1, 0);
    vector<ll> dist(n+1, 1e18);
    vector<int> par(n+1, 0);
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    dist[1] = 0;
    pq.push({ 0, 1 });

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = 1;

        for(pii &v : graph[u]) {
            if(dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
                pq.push({ dist[v.first], v.first });
                par[v.first] = u;
            }
        }
    }

    if(dist[n] == 1e18) {
        cout << -1 << '\n';
    } else {
        vector<int> ans;

        int c = n;
        while(c != 0) {
            ans.pb(c);
            c = par[c];
        }
        reverse(all(ans));
        for(int &x : ans) cout << x << " ";
        cout << '\n';
    }

    return 0;
}