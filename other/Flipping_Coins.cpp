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

struct SegTree {
    int n;
    vector<int> tree;
    vector<bool> lazy;

    SegTree(int n) : n(n), tree(4*n+5, 0), lazy(4*n+5, 0) {}

    void push(int u, int tl, int tr) {
        if(lazy[u] == 0) return ;
        tree[u] = (tr - tl + 1) - tree[u];
        if(tl != tr) {
            lazy[2*u] = !lazy[2*u];
            lazy[2*u+1] = !lazy[2*u+1];
        }
        lazy[u] = 0;
    }

    void update(int u, int tl, int tr, int l, int r) {
        push(u, tl, tr);
        if(tl > tr || l > tr || tl > r) return ;

        if(l <= tl && tr <= r) {
            lazy[u] = !lazy[u];
            push(u, tl, tr);
            return ;
        }

        int tm = (tl + tr) / 2;
        update(2*u, tl, tm, l, r);
        update(2*u+1, tm+1, tr, l, r);
        tree[u] = tree[2*u] + tree[2*u+1];
    }

    int query(int u, int tl, int tr, int l, int r) {
        if(tl > tr || l > tr || tl > r) return 0;
        push(u, tl, tr);
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return query(2*u, tl, tm, l, r)
        + query(2*u+1, tm+1, tr, l, r);
    }

    void update(int l, int r) {
        update(1, 0, n-1, l, r);
    }

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    
};

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;

    SegTree tree(n+5);

    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;

        if(t == 0) tree.update(a, b);
        else cout << tree.query(a, b) << '\n';
    }

    return 0;
}