#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector<int> v;
    vector<ll> tree;
    vector<ll> lazy;

    SegTree(vector<int> const &_v) {
        this->v = _v;
        n = sz(v);
        tree.resize(4*n+5, 0);
        lazy.resize(4*n+5, 0);
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

    void update(int u, int tl, int tr, int l, int r) {
        push(u, tl, tr);
        if(tl > tr || l > tr || tl > r) return ;

        if(l <= tl && tr <= r) {
            lazy[u]++;
            push(u, tl, tr);
            return ;
        }

        int tm = (tl + tr) / 2;
        update(2*u, tl, tm, l, r);
        update(2*u+1, tm+1, tr, l, r);
        tree[u] = tree[2*u] + tree[2*u+1];
    }

    ll query(int u, int tl, int tr, int pos) {
        if(tl > tr || tl > pos || pos > tr) return 0;
        push(u, tl, tr);
        if(tl == tr) return tree[u];
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            return query(2*u, tl, tm, pos);
        return query(2*u+1, tm+1, tr, pos);
    }

    void update(int l, int r) {
        update(1, 0, n-1, l, r);
    }

    ll query(int pos) {
        return query(1, 0, n-1, pos);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    sort(all(v));

    SegTree tree(v);
    tree.build(1, 0, n-1);

    auto binSearch = [&](int l, int r, function<bool(int)> f) {
        int ans = n;

        while(l <= r) {
            int mid = (l + r) / 2;
            
            if(f(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    };

    while(q--) {
        char t;
        cin >> t;

        if(t == 'F') {
            int c, h;
            cin >> c >> h;

            int q_l = binSearch(0, n-1, [&](int x) {
                return tree.query(x) >= h;
            });

            int q_r = q_l + c - 1;

            if(q_r >= n-1) {
                tree.update(q_l, q_r);
                continue;
            }

            int newL = binSearch(q_l, n-1, [&](int x) {
                return tree.query(x) >= tree.query(q_r);
            });

            int newR = binSearch(newL, n-1, [&](int x) {
                return tree.query(x) > tree.query(q_r);
            }) - 1;

            tree.update(q_l, newL-1);
            tree.update(newR - c + newL - q_l + 1, newR);

        } else {
            int a, b;
            cin >> a >> b;

            if(tree.query(n-1) < a) {
                cout << 0 << '\n';
                continue;
            }

            int l = binSearch(0, n-1, [&](int x) {
                return tree.query(x) >= a;
            });

            int r = binSearch(0, n-1, [&](int x) {
                return tree.query(x) > b;
            });

            cout << r - l << '\n';
        }
    }

    return 0;
}