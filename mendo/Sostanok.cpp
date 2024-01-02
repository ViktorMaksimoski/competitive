#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

struct SegTree {
    int n;
    vector<ll> v;
    vector<pll> tree;

    SegTree(vector<pii> &_v) {
        n = _v.size();
        v.resize(n);
        tree.resize(4*n+5);
        for(int i=0; i<n; i++) v[i] = _v[i].first + _v[i].second;
        build(1, 0, n-1);
    }

    pll merge(pll a, pll b) {
        if(a.first > b.first) return a;
        return b;
    }

    void build(int u, int tl, int tr) {
        if(tl == tr) {
            tree[u] = {v[tl], tl};
        } else {
            int tm = (tl + tr) / 2;
            build(2*u, tl, tm);
            build(2*u+1, tm+1, tr);
            tree[u] = merge(tree[2*u], tree[2*u+1]);
        }
    }

    pll query(int u, int tl, int tr, int l, int r) {
        if(tl > tr || l > tr || tl > r) return pll{0, 0};
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return merge(
            query(2*u, tl, tm, l, r),
            query(2*u+1, tm+1, tr, l, r)
        );
    }   

    pll query(int l, int r) { return query(1, 0, n-1, l, r); }
};

struct DSU {
    int n;
    vector<int> par;

    DSU(int _n) {
        n = _n;
        par.resize(n);
        for(int i=0; i<n; i++) par[i] = i;
    }

    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    bool uni(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return 0;

        par[a] = b;

        return 1;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pii> v(n);
    for(auto &x : v) cin >> x.first >> x.second;

    SegTree tree(v);
    DSU dsu(n);
    vector<int> rp(n);

    for(int i=0; i<n; i++) {
        int l=i, r=n-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(v[mid].first - v[i].first <= v[i].second) rp[i] = mid, l = mid + 1;
            else r = mid - 1;
        }
        
        if(i == rp[i]) continue;
        pll mx = tree.query(i, rp[i]);
        if(mx.second == i) continue;
        dsu.uni(i, mx.second);
    }

    for(int i=0; i<n; i++) {
        int p = dsu.find(i);
        cout << rp[p] - i + 1 << '\n';
    }
    
    return 0;
}