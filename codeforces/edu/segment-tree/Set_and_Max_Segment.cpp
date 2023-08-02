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

struct Node {
    ll seg;
    ll pref;
    ll suf;
    ll sum;

    Node operator+(Node &b) {
        Node res;

        res.sum = sum + b.sum;
        res.pref = max(pref, sum + b.pref);
        res.suf = max(b.suf, suf + b.sum);
        res.seg = max({ seg, b.seg, suf + b.pref });

        return res;
    }
};

struct SegTree {
    int n;
    vector<Node> tree;
    vector<ll> lazy;

    SegTree(int n) : n(n), tree(4*n+5), lazy(4*n+5, 1e10) {}

    void modify(int u, int tl, int tr, ll val) {
        tree[u].sum = (tr - tl + 1) * val;
        tree[u].seg = max(0ll, tree[u].sum);
        tree[u].pref = max(0ll, tree[u].sum);
        tree[u].suf = max(0ll, tree[u].sum);
    }

    void push(int u, int tl, int tr) {
        if(lazy[u] == 1e10) return ;
        modify(u, tl, tr, lazy[u]);
        if(tl != tr) {
            lazy[2*u] = lazy[u];
            lazy[2*u+1] = lazy[u];
        }
        lazy[u] = 1e10;
    }

    void update(int u, int tl, int tr, int l, int r, int val) {
        push(u, tl, tr);
        if(tl > r || l > tr || l > r) return ;
        if(l <= tl && tr <= r) {
            lazy[u] = val;
            push(u, tl, tr);
            return ;
        }
        
        int tm = (tl + tr) / 2;
        update(2*u, tl, tm, l, r, val);
        update(2*u+1, tm+1, tr, l, r, val);
        tree[u] = tree[2*u] + tree[2*u+1];
    }

    Node query(int u, int tl, int tr, int l, int r) {
        if(tl > r || l > tr) return Node{0, 0, 0, 0};
        push(u, tl, tr);
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        Node d1 = query(2*u, tl, tm, l, r);
        Node d2 = query(2*u+1, tm+1, tr, l, r);
        return d1 + d2;
    }

    void update(int l, int r, int val) {
        update(1, 0, n-1, l, r, val);
    }

    Node query() {
        return query(1, 0, n-1, 0, n-1);
    }

    Node query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;

    SegTree tree(n);
    while(q--) {
        int a, b, c;
        cin >> a >> b >> c;
        tree.update(a, b-1, c);
        cout << tree.query().seg << '\n';
    }

    return 0;
}