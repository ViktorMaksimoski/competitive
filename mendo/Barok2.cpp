#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int L, W, N, B;

struct SegTree {
    int n;
    vector<pii> tree;
    vector<short> lazy;

    SegTree(int _n) {
        n = _n;
        tree.resize(4*n+5);
        lazy.resize(4*n+5);
        build(1, 0, n-1);
    }

    pii merge(pii a, pii b) {
        if(a.first < b.first) return a;
        if(a.first > b.first) return b;
        return pii{a.first, a.second + b.second};
    }

    void build(int u, int tl, int tr) {
        if(tl == tr) {
            tree[u] = {0, 1};
        } else {
            int tm = (tl + tr) / 2;
            build(2*u, tl, tm);
            build(2*u+1, tm+1, tr);
            tree[u] = merge(tree[2*u], tree[2*u+1]);
        }
    }

    void push(int u, int tl, int tr) {
        if(!lazy[u]) return ;
        tree[u].first += lazy[u];

        if(tl != tr) {
            lazy[2*u] += lazy[u];
            lazy[2*u+1] += lazy[u];
        }

        lazy[u] = 0;
    }

    void update(int u, int tl, int tr, int l, int r, int val) {
        push(u, tl, tr);
        if(tl > tr || l > tr || tl > r) return ;

        if(l <= tl && tr <= r) {
            lazy[u] += val;
            push(u, tl, tr);
            return ;
        }

        int tm = (tl + tr) / 2;
        update(2*u, tl, tm, l, r, val);
        update(2*u+1, tm+1, tr, l, r, val);
        tree[u] = merge(tree[2*u], tree[2*u+1]); 
    }

    void update(int l, int r, int val) { update(1, 0, n-1, l, r, val); }

    int query() {
        if(tree[1].first != 0) return n;
        return n - tree[1].second;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> W >> N >> B;
    vector<pii> in_events[L+1], out_events[L+1];

    for(short i=0; i<B; i++) {
        int r, c;
        cin >> r >> c;
        r--, c--;
        in_events[max(0, r - N)].push_back({ max(0, c - N), min(W - 1, c + N) });
        out_events[min(L - 1, r + N)].push_back({ max(0, c - N), min(W - 1, c + N) });
    }

    ll ans = 0;
    SegTree tree(W);

    for(int i=0; i<L; i++) {
        for(pii &e : in_events[i])
            tree.update(e.first, e.second, 1);
        ans += tree.query();
        for(pii &e : out_events[i])
            tree.update(e.first, e.second, -1);
    }

    cout << ans << '\n';
    return 0;
}