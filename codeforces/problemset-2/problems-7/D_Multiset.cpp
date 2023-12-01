#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
//#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n) : n(n), tree(4*n+5) {}

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

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }

    int find(int u, int tl, int tr, int k) {
        if(k > tree[u]) return -1;
        if(tl == tr) return tl;
        int tm = (tl + tr) / 2;
        if(k <= tree[2*u])
            return find(2*u, tl, tm, k);
        return find(2*u+1, tm+1, tr, k - tree[2*u]);
    }

    int find(int k) {
        return find(1, 0, n-1, k);
    }
};

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;

    SegTree tree(n+1);
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        tree.update(x, 1);
    }

    for(int i=0; i<q; i++) {
        int x;
        cin >> x;

        if(x > 0) {
            tree.update(x, 1);
        } else {
            tree.update(tree.find(abs(x)), -1);
        }
    }

    cout << max(0, tree.find(1)) << '\n';
    return 0;
}