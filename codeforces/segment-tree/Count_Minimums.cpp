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

struct SegTree {
    int n;
    vector<int> v;
    vector<pii> tree;

    SegTree(vector<int> const &v) {
        this->n = sz(v);
        this->v = v;
        tree.resize(4*n+5);
        build(1, 0, n-1);
    }

    pii combine(pii a, pii b) {
        if(a.first == b.first)
            return make_pair(a.first, a.second + b.second);
        else if(a.first > b.first)
            return make_pair(b.first, b.second);
        else
            return make_pair(a.first, a.second);
    }

    void build(int u, int l, int r) {
        if(l == r) {
            tree[u] = make_pair(v[l], 1);
        } else {
            int m = (l + r) / 2;
            build(2*u, l, m);
            build(2*u+1, m+1, r);
            tree[u] = combine(tree[2*u], tree[2*u+1]);
        }
    }

    pii query(int u, int tl, int tr, int l, int r) {
        if(l > r) return make_pair(INT_MAX, 0);
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return combine(
            query(2*u, tl, tm, l, min(r, tm)),
            query(2*u+1, tm+1, tr, max(tm+1, l), r)
        );
    }

    void update(int u, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            tree[u] = { val, 1 };
            v[tl] = val;
        } else {
            int tm = (tl + tr) / 2;
            if(tl <= pos && pos <= tm)
                update(2*u, tl, tm, pos, val);
            else
                update(2*u+1, tm+1, tr, pos, val);
            tree[u] = combine(tree[2*u], tree[2*u+1]);
        }
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
        int t, a, b;
        cin >> t >> a >> b;

        if(t == 1) {
            tree.update(1, 0, n-1, a, b);
        } else {
            pii res = tree.query(1, 0, n-1, a, b-1);
            cout << res.first << " " << res.second << '\n';
        }
    }

    return 0;
}