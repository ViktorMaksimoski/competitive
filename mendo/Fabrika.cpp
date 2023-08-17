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

int L, R;
vector<vector<int> > graph;
vector<bool> vis;
vector<int> left_of, right_of;

bool find_match(int u) {
    if(vis[u]) return false;
    vis[u] = true;

    for(int &v : graph[u]) {
        if(left_of[v] != -1) continue;
        left_of[v] = u;
        right_of[u] = v;
        return true;
    }

    for(int &v : graph[u]) {
        int curr = left_of[v];
        if(find_match(curr)) {
            left_of[v] = u;
            right_of[u] = v;
            return true;
        }
    }

    return false;
}

int kuhn(int n) {
    int matched = 0;

    for(int i=1; i<=n; i++) {
        if(graph[i].size() == 0) continue;
        fill(all(vis), 0);
        matched += find_match(i);
    }

    return matched;
}

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;
    graph.resize(n+1);
    vis.resize(n+1);
    left_of.resize(n+1, -1);
    right_of.resize(n+1, -1);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    cout << kuhn(n) << '\n';
    return 0;
}