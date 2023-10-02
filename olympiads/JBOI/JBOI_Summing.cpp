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

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;

    vector<vector<int> > graph(n+1);
    vector<int> indegree(n+1);
    vector<int> val(n+1);

    for(int i=1; i<=n; i++) {
        cin >> val[i];
        int a;
        cin >> a;
        if(a != -1) {
            indegree[i]++;
            graph[a+1].push_back(i);
        }
    }

    vector<int> topo;
    queue<int> q;
    vector<set<ll> > dp(n+1);
    set<ll> total;

    for(int i=1; i<=n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            dp[i].insert(val[i]);
            total.insert(val[i]);
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        topo.push_back(u);

        for(int &v : graph[u]) {
            indegree[v]--;
            if(!indegree[v]) q.push(v);
        }
    }

    for(int &u : topo) {
        for(int &v : graph[u]) {
            for(const ll &x : dp[u]) {
                dp[v].insert(x + val[v]);
                total.insert(x + val[v]);
            }
        }
    }

    vector<ll> v(all(total));
    
    while(m--) {
        ll x;
        cin >> x;

        int l=0, r=sz(v)-1;
        int ans = -1;

        while(l <= r) {
            int mid = (l + r) / 2;
            if(v[mid] <= x) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

        if(ans == -1) cout << "none\n";
        else cout << v[ans] << '\n';
    }

    return 0;
}