#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define pii pair<int, int>
#define pll pair<long long, long long>
#define int long long
#define debug(x) cout << #x << " = " << x << endl
#define pb push_back
#define eb emplace_back
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

template <class T>
struct DSU {
    vector<T> parent;
    vector<ll> size;
    int components;

    DSU(int n) {
        parent.resize(n+1);
        for(int i=0; i<n+1; i++) parent[i] = i;
        size.resize(n+1, 1);
        components = n;
    }

    T find(T x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    T getSize(T x) {
        return size[find(x)];
    }

    bool uni(T a, T b) {
        T leaderA = find(a), leaderB = find(b);

        if(leaderA == leaderB) {
            return false;
        }

        components--;

        if(size[leaderA] > size[leaderB]) swap(leaderA, leaderB);

        parent[leaderA] = leaderB;
        size[leaderB] += size[leaderA];
        return true;
    }

    int getComponents() {
        return components;
    }

    bool same_set(T a, T b) {
        return find(a) == find(b);
    }
};

vector<vector<int> > graph;
vector<int> depth;

void dfs(int u, int p) {
    for(int &v : graph[u]) {
        if(v == p) continue;
        depth[v] = min(depth[v], depth[u] + 1);
        dfs(v, u);
    }
}

bool cmp(pll &a, pll &b) {
    return (a.first > b.first);
}

int32_t main() {
    setIO();

    int n;
    cin >> n;
    graph.resize(n);
    depth.resize(n, 1e9);

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    DSU<ll> dsu(n);
    depth[0] = 0, depth[1] = 0;
    for(int i=0; i<2; i++) dfs(i, i);

    vector<pll> city;
    for(int i=0; i<n; i++) city.eb(depth[i], i);
    sort(all(city), cmp);

    ll ans = 0;

    for(int i=0; i<n; i++) {
        int node = city[i].second;
        int dist = city[i].first;

        int size = dsu.getSize(node);
        vector<int> get;

        for(int &next : graph[node]) {
            if(dsu.same_set(node, next)) continue;
            if(depth[next] < dist) continue;
            get.pb(next);
            size += dsu.getSize(next);
        }

        for(int &next : get) {
            size -= dsu.getSize(next);
            ans += (dist * size * dsu.getSize(next));
        }

        for(int &next : get) dsu.uni(node, next);

    }

    cout << ans << '\n';
    return 0;
}