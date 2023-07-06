#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    if(name != "") setUSA(name);
}

vector<vector<int> > graph;
vector<int> in, out, val;
int timer = 0;

void euler(int u, int p) {
    in[u] = timer++;

    for(int &v : graph[u]) {
        if(v == p) continue;
        euler(v, u);
    }

    out[u] = timer;
}

// tree type, constructor vector type
template <class T, class U>
struct BIT {
    vector<T> tree;
    vector<U> v;
    int n;

    BIT(int x) {
        tree.resize(x, 0);
        v.resize(x, 0);
        n = x;
    }

    BIT(vector<U> const &v) : BIT(v.size()) {
        this->v = v;
        for(int i=0; i<v.size(); i++)
            update(i, v[i]);
    }

    void set(int x, int d) {
        update(x, d - v[x]);
    }

    void update(int x, int d) {
        v[x] += d;
        for(; x < n; x = x | (x + 1))
            tree[x] += d;
    }

    T sum(int id) {
        T s = 0;

        for(; id >= 0; id = (id & (id + 1)) - 1)
            s += tree[id];
        return s;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
};

int main() {
    setIO();

    int n, q;
    cin >> n >> q;
    graph.resize(n);
    in.resize(n, 0);
    out.resize(n, 0);
    val.resize(n, 0);
    for(int &x : val) cin >> x;

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    euler(0, -1);
    BIT<ll, int> bit(n);
    for(int i=0; i<n; i++) bit.set(in[i], val[i]);

    // cout << "in : ";
    // for(int &x : in) cout << x << " ";
    // cout << "\nout: ";
    // for(int &x : out) cout << x << " ";
    // cout << '\n';

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int a, b;
            cin >> a >> b;
            bit.set(in[a-1], b);
        } else {
            int a;
            cin >> a;
            ll S = bit.sum(out[a-1] - 1);
            ll s = 0;
            if(in[a-1] != 0)
                s = bit.sum(in[a-1] - 1);

            cout << S - s << '\n';
        }
    }

    return 0;
}