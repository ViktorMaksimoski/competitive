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

vector<vector<int> > graph;
vector<ll> x, y;

void dfs(int u, int p, ll len, int d) {
    for(int &v : graph[u]) {
        if(v == p) continue;
        x[v] = x[u], y[v] = y[u];
        d = (d + 1) % 4;
        if(d == 0) x[v] += len;
        if(d == 1) y[v] += len;
        if(d == 2) x[v] -= len;
        if(d == 3) y[v] -= len;
        dfs(v, u, len/2, (d+2)%4);
    }
}

int32_t main() {
    setIO();

    int n;
    cin >> n;
    graph.resize(n+1);
    x.resize(n+1);
    y.resize(n+1);

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<=n; i++) {
        if(sz(graph[i]) < 5) continue;
        cout << "NO\n";
        return 0;
    }

    dfs(1, 0, 1<<n, 0);

    cout << "YES\n";
    for(int i=1; i<=n; i++) cout << x[i] << " " << y[i] << '\n';
    return 0;
}