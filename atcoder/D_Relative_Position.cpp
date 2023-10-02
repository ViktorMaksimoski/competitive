#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
//#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct Node {
    int to;
    ll x, y;
};

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;
    vector<vector<Node> > graph(n+1);

    for(int i=0; i<m; i++) {
        int a, b;
        ll c, d;
        cin >> a >> b >> c >> d;

        graph[a].push_back(Node{b, c, d});
        graph[b].push_back(Node{a, -c, -d});
    }

    vector<bool> ok(n+1, 0);
    ok[1] = 1;
    vector<pll> ans(n+1);
    ans[1] = {0, 0};

    vector<bool> vis(n+1, 0);
    queue<Node> q;
    q.push({ 1, 0, 0 });
    vis[1] = true;

    while(!q.empty()) {
        Node u = q.front();
        q.pop();

        ans[u.to] = {u.x, u.y};
        ok[u.to] = 1;

        for(Node &v : graph[u.to]) {
            if(vis[v.to]) continue;
            q.push({ v.to, u.x + v.x, u.y + v.y });
            vis[v.to] = true;
        }
    }

    for(int i=1; i<=n; i++) {
        if(ok[i]) {
            cout << ans[i].first << " " << ans[i].second << '\n';
        } else {
            cout << "undecidable" << '\n';
        }
    }
    return 0;
}