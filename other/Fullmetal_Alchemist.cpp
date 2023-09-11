#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;

    vector<string> v(n);
    for(string &s : v) cin >> s;

    ll mst = 0;

    vector<bool> vis(n+1);
    priority_queue<pll, vector<pll>, greater<pll> > pq;

    pq.push({ 0, 0 });

    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = true;

        mst = max(mst, d);

        //cout << u << " " << d << '\n';

        for(int i=0; i<n; i++) {
            if(u == i) continue;
            if(vis[i]) continue;
            int dist= 0;

            for(int j=0; j<m; j++) {
                dist = max(dist, 1ll * abs(v[i][j] - v[u][j]));
            }

            pq.push({ dist, i });
        }
    }

    cout << mst << '\n';
    return 0;
}