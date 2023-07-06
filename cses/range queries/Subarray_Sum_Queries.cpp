#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<long long, long long>
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

struct Node {
    ll seg, pref, suf, sum;
};

struct SegTree {
    int n;
    vector<int> v;
    vector<Node> tree;

    SegTree(vector<int> const &v) {
        this->n = sz(v);
        this->v = v;
        tree.resize(4*n+5);
        build(1, 0, n-1);
    }

    Node combine(Node a, Node b) {
        Node res;

        res.sum = a.sum + b.sum;
        res.pref = max(a.pref, a.sum + b.pref);
        res.suf = max(b.suf, b.sum + a.suf);
        res.seg = max({ a.seg, b.seg, a.suf + b.pref });

        return res;
    }

    Node createNode(int x) {
        Node node;
        node.sum = x;
        node.pref = max(x, 0);
        node.suf = max(x, 0);
        node.seg = max(x, 0);
        return node;
    }

    void build(int u, int l, int r) {
        if(l == r) {
            tree[u] = createNode(v[l]);
        } else {
            int m = (l + r) / 2;
            build(2*u, l, m);
            build(2*u+1, m+1, r);
            tree[u] = combine(tree[2*u], tree[2*u+1]);
        }
    }

    void update(int u, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            tree[u] = createNode(val);
        } else {
            int tm = (tl + tr) / 2;
            if(tl <= pos && pos <= tm)
                update(2*u, tl, tm, pos, val);
            else
                update(2*u+1, tm+1, tr, pos, val);
            tree[u] = combine(tree[2*u], tree[2*u+1]);
        }
    }

    Node query(int u, int tl, int tr, int l, int r) {
        if(l > r) return createNode(0);
        if(l == tl && tr == r) return tree[u];

        int tm = (tl + tr) / 2;
        return combine(
            query(2*u, tl, tm, l, min(tm, r)),
            query(2*u+1, tm+1, tr, max(tm+1, l), r)
        );
    }

    Node query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }
};

int main() {
    setIO();

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    SegTree tree(v);
    while(q--) {
        int a, b;
        cin >> a >> b;
        tree.update(a-1, b);
        cout << tree.query(0, n-1).seg << '\n';
    }

    return 0;
}