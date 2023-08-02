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
    vector<ll> added, mult;

    SegTree(int n) : n(n), added(4*n+5, 0), mult(4*n+5, 1) {}

    void build(int u, int tl, int tr) {
        if(tl == tr) {
            added[u] = 1;
        } else {
            int tm = (tl + tr) / 2;
            build(2*u, tl, tm);
            build(2*u+1, tm+1, tr);
            added[u] = add_op(added[2*u], added[2*u+1]);
        }
    }

    ll add_op(ll a, ll b) {
        return (a + b) % mod;
    }

    ll mult_op(ll a, ll b) {
        return ((a % mod) * (b % mod)) % mod;
    }

    void update(int u, int tl, int tr, int l, int r, int val) {
        if(tl > r || l > tr) return ;
        if(l <= tl && tr <= r) {
            added[u] = mult_op(added[u], val);
            mult[u] = mult_op(mult[u], val);
            return ;
        }
        int tm = (tl + tr) / 2;
        update(2*u, tl, tm, l, r, val);
        update(2*u+1, tm+1, tr, l, r, val);
        added[u] = add_op(added[2*u], added[2*u+1]);
        added[u] = mult_op(added[u], mult[u]);
    }

    ll query(int u, int tl, int tr, int l, int r) {
        if(tl > r || l > tr) return 0;
        if(l <= tl && tr <= r) return added[u];
        int tm = (tl + tr) / 2;
        auto d1 = query(2*u, tl, tm, l, r);
        auto d2 = query(2*u+1, tm+1, tr, l, r);
        auto res = add_op(d1, d2);
        res = mult_op(res, mult[u]);
        return res;
    }

    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    void update(int l, int r, int val) {
        update(1, 0, n-1, l, r, val);
    }
};

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;

    SegTree tree(n);
    tree.build(1, 0, n-1);
    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            tree.update(a, b-1, c);
        } else {
            int a, b;
            cin >> a >> b;
            cout << tree.query(a, b-1) << '\n';
        }
    }

    return 0;
}