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
        tree.resize(4*n+5, 0);
    }

    void update(int u, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            tree[u] += val;
        } else {
            int tm = (tl + tr) / 2;
            if(pos <= tm)
                update(2*u, tl, tm, pos, val);
            else
                update(2*u+1, tm+1, tr, pos, val);
            tree[u] = (tree[2*u] + tree[2*u+1]) % mod;
        }
    }

    ll query(int u, int tl, int tr, int l, int r) {
        if(l > r) return 0;
        if(l == tl && tr == r) return tree[u];
        int tm = (tl + tr) / 2;
        return (
            query(2*u, tl, tm, l, min(tm, r)) +
            query(2*u+1, tm+1, tr, max(tm+1, l), r)
        ) % mod;
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }

    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

int main() {
    setIO();

    int n;
    cin >> n;

    vector<int> v(n);
    for(int &x : v) cin >> x;
    vector<int> v2 = v;
    sort(all(v2));
    v2.erase(unique(all(v2)), v2.end());

    vector<ll> dp(n, 0);

    ll ans = 0;
    SegTree tree(n);
    for(int i=0; i<n; i++) {
        int pos = lower_bound(all(v2), v[i]) - v2.begin();
        ll res = tree.query(0, pos-1) + 1;

        ans += res;
        ans %= mod;

        dp[i] = ans;
        tree.update(pos, res);
    }

    cout << dp[n-1] << '\n';
    return 0;
}