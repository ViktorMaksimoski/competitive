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

    vector<int> vis(2*int(1e4), false);
    vector<int> dist(2*int(1e4), 1e9);
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    pq.push({0, n});
    vis[n] = true;
    dist[n] = 0;
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(u == m) {
            cout << dist[u] << '\n';
            return 0;
        }

        if(2*u >= 0 && 2*u < 2e4 && dist[2*u] > dist[u] + 1) {
            vis[2*u] = true;
            dist[2*u] = dist[u] + 1;
            pq.push({ dist[u]+1, 2*u });
        }

        if(u-1 >= 0 && u-1 < 2e4 && dist[u-1] > dist[u] + 1) {
            vis[u-1] = true;
            dist[u-1] = dist[u] + 1;
            pq.push({dist[u]+1, u-1});
        }
    }

    return 0;
}