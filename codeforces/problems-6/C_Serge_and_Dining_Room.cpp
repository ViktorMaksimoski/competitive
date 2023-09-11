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
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct SegTree {
    int n = 1e6 + 1;
    vector<int> tree;
    vector<int> lazy;

    SegTree() : tree(4*n+5, 0), lazy(4*n+5, 0) {}

    void push(int u, int tl, int tr) {
        if(lazy[u] == 0) return ;

        tree[u] += lazy[u];
        
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
        tree[u] = min(tree[2*u], tree[2*u+1]);
    }

    void update(int l, int r, int val) {
        update(1, 1, n-1, l, r, val);
    }

    int query(int u, int tl, int tr) {
        if(tl == tr) return tl;

        int tm = (tl + tr) / 2;
        push(u, tl, tr);
        push(2*u, tl, tm);
        push(2*u+1, tm+1, tr);

        if(tree[2*u+1] < 0)
            return query(2*u+1, tm+1, tr);
        else if(tree[2*u] < 0)
            return query(2*u, tl, tm);
        return -1;
    }

    int query() {
        return query(1, 1, n-1);
    }
};

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;

    SegTree tree;
    vector<int> a(n);
    vector<int> b(m);
    for(int &x : a) {
        cin >> x;
        tree.update(1, x, -1);
    }

    for(int &x : b) {
        cin >> x;
        tree.update(1, x, 1);
    }

    int q;
    cin >> q;
    while(q--) {
        int t, x, y;
        cin >> t >> x >> y;

        if(t == 1) {
            tree.update(1, a[x-1], 1);
            a[x-1] = y;
            tree.update(1, y, -1);
        } else {
            tree.update(1, b[x-1], -1);
            b[x-1] = y;
            tree.update(1, y, 1);
        }

        int ans = tree.query();
        cout << (ans == -1 ? -1 : ans) << '\n';
    }

    return 0;
}