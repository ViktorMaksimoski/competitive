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
const int maxn = 2e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct Int {
    int val, col, id;
    bool operator<(Int &b) {
        if(col == b.col) return id < b.id;
        return col < b.col;
    }
};

struct SegTree {
    int n;
    vector<int> v;
    vector<ll> tree, lazy;

    SegTree(vector<int> &_v) {
        n = sz(_v);
        v = _v;
        tree.resize(4*n+5, 0);
        lazy.resize(4*n+5, 0);
        build(1, 0, n-1);
    }

    void build(int u, int tl, int tr) {
        if(tl == tr) {
            tree[u] = v[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(2*u, tl, tm);
            build(2*u+1, tm+1, tr);
            tree[u] = tree[2*u] + tree[2*u+1];
        }
    }

    void push(int u, int tl, int tr) {
        if(lazy[u] == 0) return ;
        tree[u] += (tr - tl + 1) * lazy[u];
        if(tl != tr) {
            lazy[2*u] += lazy[u];
            lazy[2*u+1] += lazy[u];
        }
        lazy[u] = 0;
    }
 
    void update(int u, int tl, int tr, int l, int r, int val) {
        push(u, tl, tr);
        if(tl > r || l > tr || l > r) return ;
        if(l <= tl && tr <= r) {
            lazy[u] += val;
            push(u, tl, tr);
            return ;
        }
        int tm = (tl + tr) / 2;
        update(2*u, tl, tm, l, r, val);
        update(2*u+1, tm+1, tr, l, r, val);
        tree[u] = tree[2*u] + tree[2*u+1];
    }
    
    ll query(int u, int tl, int tr, int l, int r) {
        if(tl > r || l > tr) return 0;
        push(u, tl, tr);
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return query(2*u, tl, tm, l, r)
        + query(2*u+1, tm+1, tr, l, r);
    }
 
    void update(int l, int r, int val) {
        update(1, 0, n-1, l, r, val);
    }
 
    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

int32_t main() {
    setIO();

    int n;
    cin >> n;

    vector<Int> v(n);
    vector<int> cnt(maxn, 0);
    for(int i=0; i<n; i++) cin >> v[i].val;
    for(int i=0; i<n; i++) cin >> v[i].col, cnt[v[i].col]++;
    for(int i=0; i<n; i++) v[i].id = i;

    sort(all(v));

    vector<int> to_build(n);
    for(int i=0; i<n; i++) to_build[i] = v[i].val;

    SegTree tree(to_build);

    int q;
    cin >> q;

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int c, x;
            cin >> c >> x;
            if(!cnt[c]) continue;

            int l=0, r=n-1;
            int pos = 0;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(v[mid].col >= c) {
                    pos = mid;
                    r = mid - 1;
                } else l = mid + 1;
            } 

            if(pos > 0) tree.update(0, pos-1, x);
            if(pos + cnt[c] < n) tree.update(pos+cnt[c], n-1, x);
        } else {
            int c;
            ll y;
            cin >> c >> y;

            int l=0, r=n-1;
            int pos = 0;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(v[mid].col >= c) {
                    pos = mid;
                    r = mid - 1;
                } else l = mid + 1;
            } 

            int ans = -1;
            l = pos, r = pos + cnt[c] - 1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(tree.query(pos, mid) <= y) {
                    ans = mid;
                    l = mid + 1;
                } else r = mid - 1;
            }

            cout << (ans == -1 ? 0 : ans - pos + 1) << '\n';
        }
    }

    return 0;
}