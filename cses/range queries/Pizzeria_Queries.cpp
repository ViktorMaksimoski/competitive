#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
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
    vector<ll> tree;

    SegTree(int n) {
        this->n = n;
        tree.resize(4*n + 5, 1e10);
    }

    void update(int u, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            tree[u] = val;
        } else {
            int tm = (tl + tr) / 2;
            if(pos <= tm)
                update(2*u, tl, tm, pos, val);
            else
                update(2*u+1, tm+1, tr, pos, val);
            tree[u] = min(tree[2*u], tree[2*u+1]);
        }
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }

    ll query(int u, int tl, int tr, int l, int r) {
        if(l > r) return 1e10;
        if(l == tl && r == tr) return tree[u];
        int tm = (tl + tr) / 2;
        return min(
            query(2*u, tl, tm, l, min(r, tm)),
            query(2*u+1, tm+1, tr, max(l, tm+1), r)
        );
    }

    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

int main() {
    setIO();

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    SegTree up(n+1), down(n+1);

    auto update = [&](int x, int y) {
        up.update(x, y + x);
        down.update(x, y - x);
    };

    for(int i=1; i<=n; i++) {
        update(i, v[i-1]);
    }

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int a, b;
            cin >> a >> b;
            update(a, b);
        } else {
            int a;
            cin >> a;
            cout << min(up.query(a, n)-a, down.query(1, a)+a) << '\n';
        }
    }

    return 0;
}