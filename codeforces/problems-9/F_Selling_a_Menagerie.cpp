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

int n;
vector<vector<int> > graph, cycles;
vector<int> vis, st;

void dfs(int u, int p) {
    vis[u] = 1;
    st.push_back(u);

    for(int &v : graph[u]) {
        if(vis[v] == 0) {
            dfs(v, u);
        } else if(vis[v] == 1) {
            vector<int> v2 = {v};
            int pos = sz(st) - 1;
            while(pos && st[pos] != v) v2.push_back(st[pos]), pos--;
            cycles.push_back(v2);
        }
    }

    st.pop_back();
    vis[u] = 2;
}

void solve() {
    cin >> n;
    graph.clear();
    graph.resize(n+1);
    cycles.clear();
    cycles.resize(n+1);
    vis.clear();
    vis.resize(n+1);
    st.clear();

    vector<ll> cost(n+1);
    vector<int> indegree(n+1);
    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        graph[i].push_back(a);
        indegree[a]++;
    }

    queue<pii> q;
    for(int i=1; i<=n; i++)
        if(!indegree[i]) q.push({ i, 0 });

    for(int i=1; i<=n; i++) cin >> cost[i];
    vector<pii> d;
    while(!q.empty()) {
        int u = q.front().first;
        int x = q.front().second;
        d.push_back({ u, x });
        q.pop();

        for(int &v : graph[u]) {
            indegree[v]--;
            if(!indegree[v]) q.push({ v, x+1 });
        }
    }

    sort(all(d), [&](pii a, pii b) {
        if(a.second == b.second) return cost[a.first] > cost[b.first];
        return a.second < b.second;
    });

    for(pii &x : d) cout << x.first << " ";

    for(int i=1; i<=n; i++) {
        if(vis[i]) continue;
        dfs(i, -1);
    }

    for(int i=0; i<sz(cycles); i++) {
        if(sz(cycles[i]) == 0) continue;
        reverse(all(cycles[i]));
        int pos = 0;

        for(int j=0; j<sz(cycles[i]); j++)
            if(cost[cycles[i][j]] < cost[cycles[i][pos]]) pos = j;

        for(int j=pos+1; j<sz(cycles[i]); j++) cout << cycles[i][j] << " ";
        for(int j=0; j<=pos; j++) cout << cycles[i][j] << " ";
    }
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