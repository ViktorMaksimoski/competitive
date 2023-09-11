#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define x first 
#define y second
//#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pff = pair<float, float>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

float getDist(pff &a, pff &b) {
    float d1 = (a.x - b.x) * (a.x - b.x);
    float d2 = (a.y - b.y) * (a.y - b.y);
    return float(sqrt(d1 + d2));
}

void solve() {
    int n;
    cin >> n;

    vector<pff> points(n);
    for(pff &p : points) cin >> p.x >> p.y;

    float ans = 0.00;

    vector<bool> vis(n, 0);
    priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>> > pq;

    pq.push({ 0, 0 });

    while(!pq.empty()) {
        int u = pq.top().second;
        float d = pq.top().first;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = true;

        ans += d;

        for(int i=0; i<n; i++) {
            if(vis[i]) continue;
            pq.push({ getDist(points[u], points[i]), i });
        }
    }

    cout << setprecision(2) << fixed << ans << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        if(i) cout << '\n';
        solve();
    }

    return 0;
}