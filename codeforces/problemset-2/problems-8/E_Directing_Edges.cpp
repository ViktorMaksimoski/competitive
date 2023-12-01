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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > graph(n+1);
    vector<int> indegree(n+1);
    vector<pii> edges;

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> c >> a >> b;
        if(c) {
            graph[a].push_back(b);
            indegree[b]++;
        } else {
            edges.push_back({ a, b });
        }
    }

    queue<int> q;
    vector<int> topo;
    vector<int> timer(n+1);

    for(int i=1; i<=n; i++)
        if(!indegree[i]) q.push(i);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        topo.push_back(u);
        timer[u] = sz(topo);

        for(int &v : graph[u]) {
            indegree[v]--;
            if(!indegree[v])
                q.push(v);
        }
    }

    if(sz(topo) != n) {
        cout << "NO\n";
        return ;
    }

    cout << "YES\n";

    for(int i=1; i<=n; i++)
        for(int &j : graph[i])
            cout << i << " " << j << '\n';

    for(pii &x : edges) {
        if(timer[x.first] > timer[x.second]) swap(x.first, x.second);
        cout << x.first << " " << x.second << '\n';
    }
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}