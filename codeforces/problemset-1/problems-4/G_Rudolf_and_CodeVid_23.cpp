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

struct Medicine {
    int days;
    int remove;
    int add;
};

ll decimal() {
    str s;
    cin >> s;
    ll ans = 0;
    for(int i=0; i<sz(s); i++) {
        if(s[i] == '1') ans += (1 << (sz(s)-i-1));
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    ll start = decimal();

    vector<Medicine> v(m);
    for(Medicine &med : v) {
        cin >> med.days;
        med.remove = decimal();
        med.add = decimal();
    }

    vector<ll> dist(1 << n, 1e18);
    vector<bool> vis(1 << n, false);
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    dist[start] = 0;
    pq.push({ 0, start });

    while(!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        if(vis[node]) continue;
        vis[node] = true;

        for(Medicine &med : v) {
            int mask = node & (((1 << n) - 1) & (~med.remove));
            mask |= med.add;
            if(dist[mask] > dist[node] + med.days) {
                dist[mask] = dist[node] + med.days;
                pq.push({ dist[mask], mask });
            }
        }
    }

    if(dist[0] == 1e18)
        cout << -1 << '\n';
    else
        cout << dist[0] << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}