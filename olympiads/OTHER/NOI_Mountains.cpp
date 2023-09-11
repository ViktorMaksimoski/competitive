#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define int long long
using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n) : n(n), tree(4*n+5) {}

    void update(int u, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            tree[u] += val;
        } else {
            int tm = (tl + tr) / 2;
            if(pos <= tm)
                update(2*u, tl, tm, pos, val);
            else
                update(2*u+1, tm+1, tr, pos, val);
            tree[u] = tree[2*u] + tree[2*u+1];
        }
    }

    int query(int u, int tl, int tr, int l, int r) {
        if(tl > tr || l > tr || tl > r) return 0;
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return query(2*u, tl, tm, l, r)
        + query(2*u+1, tm+1, tr, l, r);
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<ll> v(n);
    for(ll &x : v) cin >> x;

    vector<ll> tmp(v);
    map<ll, int> key;
    sort(all(tmp));
    uniq(tmp);

    for(int i=0; i<tmp.size(); i++)
        key[tmp[i]] = i;
    
    vector<int> dp_left(n), dp_right(n);
    SegTree tree_left(tmp.size());
    SegTree tree_right(tmp.size());

    //calcs elements smaller than x left from x
    for(int i=0; i<n; i++) {
        int pos = key[v[i]];
        dp_left[i] = tree_left.query(0, pos-1);
        tree_left.update(pos, 1);
    }

    //calcs elements smaller than x right from x
    for(int i=n-1; i>=0; i--) {
        int pos = key[v[i]];
        dp_right[i] = tree_right.query(0, pos-1);
        tree_right.update(pos, 1);
    }

    ll ans = 0;
    for(int i=0; i<n; i++)
        ans += 1ll * (dp_left[i] * dp_right[i]);
    cout << ans << '\n';
    return 0;
}