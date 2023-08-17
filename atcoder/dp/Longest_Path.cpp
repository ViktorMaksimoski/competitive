#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
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

    vector<vector<int> > graph(n+1);
    vector<int> indegree(n+1, 0);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    vector<int> topo;
    queue<int> q;
    for(int i=1; i<=n; i++)
        if(!indegree[i]) q.push(i);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        topo.pb(u);
        for(int &v : graph[u])
            if(--indegree[v] == 0)
                q.push(v);
    }

    vector<int> dp(n+1, 0);

    for(int &u : topo)
        for(int &v : graph[u])
            dp[v] = max(dp[v], dp[u] + 1);
    
    cout << *max_element(all(dp)) << '\n';
    return 0;
}