#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define pii pair<int, int>
#define pll pair<long long, long long>
#define debug(x) cout << #x << " = " << x << '\n'
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

vector<vector<int> > graph;
vector<int> euler, in, out, val;
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

int main() {
    setIO();

    int n, q;
    cin >> n >> q;
    graph.resize(n+1);
    euler.resize(n, 0);
    in.resize(n+1, 0);
    out.resize(n+1, 0);
    val.resize(n+1, 0);

    for(int i=1; i<=n; i++) cin >> val[i];

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    BIT bit(n);
    for(int i=0; i<n; i++) bit.update(i, val[euler[i]]);
    
    for(int i=0; i<q; i++) {
        int t;
        cin >> t;

        if(t == 2) {
            int a;
            cin >> a;
            int x = in[a];
            int y = out[a] - 1;
            cout << bit.query(x-1, y) << '\n';
        } else {
            int a, b;
            cin >> a >> b;
            bit.set(in[a], b);
        }
    }
   
    return 0;
}