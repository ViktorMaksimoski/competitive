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
vector<int> val, sub;
vector<ll> ans1, ans2;
int n;

void dfs(int u, int p) {
    sub[u] = 1;
    for(int &v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
        sub[u] += sub[v];
    }
}

void calc(int u, int p) {
    for(int &v : graph[u]) {
        if(v == p) continue;
        ans1[u] += 1ll* (val[u] ^ val[v]) * sub[v];
        calc(v, u);
        ans1[u] += ans1[v];
    }
} 

void calc2(int u, int p) {
    for(int &v : graph[u]) {
        if(v == p) continue;
        ll res = ans2[u];
        res -= 1ll * (val[u] ^ val[v]) * sub[v];
        res += 1ll * (val[u] ^ val[v]) * (n - sub[v]);
        ans2[v] = res;
        calc2(v, u);
    }
}

void solve() {
    cin >> n;
    val.clear();
    val.resize(n+1);
    graph.clear();
    graph.resize(n+1);
    sub.clear();
    sub.resize(n+1);
    ans1.clear();
    ans1.resize(n+1);
    ans2.clear();
    ans2.resize(n+1);

    for(int i=1; i<=n; i++) cin >> val[i];

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    calc(1, 0);
    ans2[1] = ans1[1];
    calc2(1, 0);
    for(int i=1; i<=n; i++) cout << ans2[i] << " ";
    cout << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}