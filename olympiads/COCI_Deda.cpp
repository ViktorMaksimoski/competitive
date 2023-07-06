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
        tree.resize(4*n + 5, 0);
        build(1, 0, n-1);
    }

    void build(int u, int l, int r) {
        if(l == r) {
            tree[u] = 1e10;
        } else {
            int m = (l + r) / 2;
            build(2*u, l, m);
            build(2*u+1, m+1, r);
            tree[u] = min(tree[2*u], tree[2*u+1]);
        }
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

    ll query(int u, int tl, int tr, int l, int r) {
        if(l > r) return 1e10;
        if(l == tl && tr == r) return tree[u];
        int tm = (tl + tr) / 2;
        return min(
            query(2*u, tl, tm, l, min(tm, r)),
            query(2*u+1, tm+1, tr, max(tm+1, l), r)
        );
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }

    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    ll find(int a, int b) {
        ll ans = -1;

        int l=b, r=n-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(query(l, mid) <= a) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    setIO();

    int n, q;
    cin >> n >> q;

    SegTree tree(n+1);
    while(q--) {
        char t;
        int a, b;
        cin >> t >> a >> b;

        if(t == 'D')
            cout << tree.find(a, b) << '\n';
        else
            tree.update(b, a);

    }

    return 0;
}