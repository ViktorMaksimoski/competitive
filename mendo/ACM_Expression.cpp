#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;

const int mod = 45678;
const int maxn = 1e6;

int n;
vector<int> val;
vector<char> sign;

struct Node {
    int l, r;
    int blocks = 0;
    ll val;
    ll lb, rb;
};

Node merge(Node a, Node b) {
    if(a.l == maxn && a.r == maxn) return b;
    if(b.l == maxn && b.r == maxn) return a;

    Node res;
    res.l = min({ a.l, b.l, a.r, b.r });
    res.r = max({ a.l, b.l, a.r, b.r });

    if(sign[b.l] == '+') {
        res.val = (a.val + b.val) % mod;
        res.lb = a.lb % mod;
        res.rb = b.rb % mod;
        res.blocks = a.blocks + b.blocks;
    } else {
        res.blocks = a.blocks + b.blocks - 1;
        res.val = (a.val + b.val - a.rb - b.lb + (a.rb * b.lb) % mod) % mod;
        if(a.blocks == 1) res.lb = (a.lb * b.lb) % mod;
        else res.lb = a.lb % mod;
        if(b.blocks == 1) res.rb = (b.rb * a.rb) % mod;
        else res.rb = b.rb % mod;
    }

    return res;
}

struct SegTree {
    vector<Node> tree;

    SegTree() {
        tree.resize(4*n+5);
        build(1, 0, n-1);
    }

    void build(int u, int tl, int tr) {
        if(tl == tr) {
            Node nd;
            nd.blocks = 1;
            nd.val = val[tl];
            nd.l = nd.r = tl;
            nd.lb = nd.rb = nd.val;
            tree[u] = nd;
        } else {
            int tm = (tl + tr) / 2;
            build(2*u, tl, tm);
            build(2*u+1, tm+1, tr);
            tree[u] = merge(tree[2*u], tree[2*u+1]);
        }
    }

    Node query(int u, int tl, int tr, int l, int r) {
        if(tl > tr || l > tr || tl > r) {
            return Node {maxn, maxn, maxn, maxn, maxn, maxn};
        }

        if(l <= tl && tr <= r) return tree[u];

        int tm = (tl + tr) / 2;
        return merge(
            query(2*u, tl, tm, l, r),
            query(2*u+1, tm+1, tr, l, r)
        );
    }

    int query(int l, int r) { return query(1, 0, n-1, l, r).val; }
    Node get(int u) { return tree[u]; }
};

void solve() {
    cin >> n;

    val.clear();
    sign.clear();
    val.resize(n);
    sign.resize(n);

    sign[0] = '+';

    int p1=0, p2=1;
    for(int i=0; i<2*n-1; i++) {
        if(i % 2 == 0) {
            int x;
            cin >> x;
            val[p1++] = x;
        } else {
            char x;
            cin >> x;
            sign[p2++] = x;
        }
    }

    int q;
    cin >> q;
    SegTree tree;
    while(q--) {
        int l, r;
        cin >> l >> r;
        ll ans = tree.query(l-1, r-1);
        if(ans < 0) ans += mod;
        else ans %= mod;
        cout << ans << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}