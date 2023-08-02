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

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

int32_t main() {
    setIO();
    setUSA("visitfj");

    int n, t;
    cin >> n >> t;

    int mat[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> mat[i][j];

    bool vis[n][n][3];
    memset(vis, 0, sizeof(vis));
    vector<vector<vector<ll> > > dist(n, vector<vector<ll>>(n, vector<ll>(3, 1e18)));
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    dist[0][0][0] = 0;
    pq.push({ 0, 0, 0, 0 });

    while(!pq.empty()) {
        ll d = pq.top().at(0);
        auto r = pq.top().at(2);
        auto c = pq.top().at(3);
        auto m = pq.top().at(1);
        pq.pop();

        if(vis[r][c][m]) continue;
        vis[r][c][m] = true;

        for(int i=0; i<4; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];

            if(newR < 0 || newR >= n) continue;
            if(newC < 0 || newC >= n) continue;

            ll newDist = dist[r][c][m] + t;
            if(m == 2) newDist += mat[newR][newC];

            if(dist[newR][newC][(m+1)%3] > newDist) {
                dist[newR][newC][(m+1)%3] = newDist;
                pq.push({ newDist, (m+1)%3, newR, newC });
            }
        }
    }

    ll ans = min({ dist[n-1][n-1][0], dist[n-1][n-1][1], dist[n-1][n-1][2] });
    cout << ans << '\n';
    return 0;
}