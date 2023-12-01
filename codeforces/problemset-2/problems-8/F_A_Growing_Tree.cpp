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
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct BIT {
    int n;
    vector<ll> bit;
    vector<int> v;
 
    BIT(int n) : n(n+1), bit(n+1, 0), v(n+1, 0) {}
 
    void update(int x, int d) {
        v[x] += d;
        for(x++; x<n; x+=x&-x) bit[x] += d;
    }
 
    void set(int x, int d) {
        update(x, d - v[x]);
    }
 
    ll query(int x) {
        ll ans = 0;
        for(x++; x>0; x-=x&-x) ans += bit[x];
        return ans;
    }
    
    ll query(int a, int b) {
        return query(b) - query(a);
    }
 
};


vector<vector<int> > graph;
vector<int> euler, in, out;
int timer = 0;

void dfs(int u, int p) {
    euler[timer] = u;
    in[u] = timer++;

    for(int &v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
    }

    out[u] = timer;
}

void solve() {
    int q;
    cin >> q;

    graph.clear();
    graph.resize(2);
    timer = 0;
    int nodes = 1;
    vector<array<int, 3> > qus(q);

    for(int i=0; i<q; i++) {
        int t;
        cin >> t;

        if(t == 1) {
            int x;
            cin >> x;
            nodes++;
            graph.push_back({ x });
            graph[x].push_back(nodes);
            qus[i] = {1, x, 0};
        } else {
            int a, b;
            cin >> a >> b;
            qus[i] = {2, a, b};
        }
    }

    euler.clear();
    euler.resize(nodes+1);
    in.clear();
    in.resize(nodes+1);
    out.clear();
    out.resize(nodes+1);

    dfs(1, 1);
    BIT tree(nodes+5);
    int curr = 2;

    for(int i=0; i<q; i++) {
        if(qus[i][0] == 1) {
            ll res = tree.query(in[curr]);
            tree.update(in[curr], -res);
            tree.update(in[curr]+1, res);
            curr++;
        } else {
            tree.update(in[qus[i][1]], qus[i][2]);
            tree.update(out[qus[i][1]], -qus[i][2]);
        }
    }
    
    for(int i=1; i<=nodes; i++) cout << tree.query(in[i]) << " ";
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