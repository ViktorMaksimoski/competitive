#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
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
    }

    void update(int u, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            tree[u] += val;
        } else {
            int tm = (tl + tr) / 2;
            if(tl <= pos && pos <= tm)
                update(2*u, tl, tm, pos, val);
            else
                update(2*u+1, tm+1, tr, pos, val);
            
            tree[u] = tree[2*u] + tree[2*u+1];
        }
    }

    ll query(int u, int tl, int tr, int l, int r) {
        if(r < l) return 0;
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return query(2*u, tl, tm, l, min(tm, r)) +
            query(2*u+1, tm+1, tr, max(tm+1, l), r);
    }

    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }
};

int main() {
    setIO();

    int n;
    ll ans = 0;
    cin >> n;

    vector<int> v(n), g(n);
    SegTree tree1(n), tree2(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
        g[i] = tree1.query(v[i], n-1);
        tree1.update(v[i]-1, 1);
    }

    vector<ll> res(n);
    for(int i=0; i<n; i++) {
        res[i] = tree2.query(v[i], n-1);
        tree2.update(v[i]-1, g[i]);
        ans += res[i];
    }

    cout << '\n';
    cout << ans << '\n';
    return 0;
}