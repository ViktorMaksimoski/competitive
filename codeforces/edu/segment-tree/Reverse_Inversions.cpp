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
    vector<int> tree;

    SegTree(int n) : n(n), tree(4*n + 5, 0) {}

    void build(int u, int l, int r) {
        if(l == r) {
            tree[u] = 1;
            return ;
        }
        int m = (l + r) / 2;
        build(2*u, l, m);
        build(2*u+1, m+1, r);
        tree[u] = tree[2*u] + tree[2*u+1];
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
            tree[u] = tree[2*u] + tree[2*u+1];
        }
    }

    ll query(int u, int tl, int tr, int l, int r) {
        if(l > r) return 0;
        if(l == tl && tr == r) return tree[u];
        int tm = (tl + tr) / 2;
        return query(2*u, tl, tm, l, min(r, tm))
        + query(2*u+1, tm+1, tr, max(tm+1, l), r);
    }

    int find(int u, int tl, int tr, int k) {
        if(k > tree[u]) return -1;
        if(tl == tr) return tl+1;
        int tm = (tl + tr) / 2;
        if(k <= tree[2*u])
            return find(2*u, tl, tm, k);
        return find(2*u+1, tm+1, tr, k - tree[2*u]);
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }

    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    int find(int k) {
        return find(1, 0, n-1, k);
    }
};

int main() {
    setIO();

    int n, now;
    cin >> n;
    now = n;

    SegTree tree(n); 
    tree.build(1, 0, n-1);

    vector<int> v(n);
    for(int &x : v) cin >> x;

    reverse(all(v));
    vector<int> ans;
    for(int &x : v) {
        int res = tree.find(now-x);
        tree.update(res-1, -1);
        ans.pb(res);
        now--;
    }

    reverse(all(ans));
    for(int &x : ans) cout << x << " ";
    return 0;
}