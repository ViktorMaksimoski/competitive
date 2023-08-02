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
    vector<int> v;
    vector<int> tree;

    SegTree(vector<int> const &v) {
        this->n = sz(v);
        this->v = v;
        tree.resize(4*n +5, 0);
        build(1, 0, n-1);
    }

    void build(int u, int l, int r) {
        if(l == r) {
            tree[u] = v[l];
        } else {
            int m = (l + r) / 2;
            build(2*u, l, m);
            build(2*u+1, m+1, r);
            tree[u] = max(tree[2*u], tree[2*u+1]);
        }
    }

    void update(int u, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            tree[u] = val;
        } else {
            int tm = (tl + tr) / 2;
            if(tl <= pos && pos <= tm)
                update(2*u, tl, tm, pos, val);
            else
                update(2*u+1, tm+1, tr, pos, val);
            tree[u] = max(tree[2*u], tree[2*u+1]);
        }
    }

    int find(int u, int tl, int tr, int k) {
        if(tree[u] < k) return -1;
        if(tl == tr) return tl;
        int tm = (tl + tr) / 2;
        if(tree[2*u] >= k)
            return find(2*u, tl, tm, k);
        return find(2*u+1, tm+1, tr, k);
    }

    int find(int k) {
        return find(1, 0, n-1, k);
    }

    void update(int pos, int val) {
        update(1,0,n-1,pos,val);
    }
};

int main() {
    setIO();

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    SegTree tree(v);
    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int a, b;
            cin >> a >> b;
            tree.update(a, b);
        } else {
            int a;
            cin >> a;
            cout << tree.find(a) << '\n';
        }
    }

    return 0;
}