#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    if(name != "") setUSA(name);
}

//tree type, vector type
template <class T, class U>
struct SegTree {
    int n;
    vector<T> tree, lazy;
    vector<U> v;

    SegTree(vector<U> const &v) {
        n = v.size();
        tree.resize(4*n+5);
        lazy.resize(4*n+5, -1);
        this->v = v;
        build(1, 0, n-1);
    }

    T combine(T a, T b) {
        return a + b;
    }

    void getLazy(int node) {
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
        lazy[node] = 0;
    }

    void build(int node, int l, int r) {
        if(l == r) {
            tree[node] = v[l];
        } else {
            int mid = (l + r) / 2;
            build(2*node, l, mid);
            build(2*node+1, mid+1, r);
            tree[node] = combine(tree[2*node], tree[2*node+1]);
        }
    }

    T query(int node, int tl, int tr, int l, int r) {
        if(l > r) return 0;
        if(l == tl && tr == r) return tree[node];

        int mid = (tl + tr) / 2;

        return combine(query(2*node, tl, mid, l, min(mid, r)), query(2*node+1, mid+1, tr, max(mid+1, l), r));
    }

    void update(int node, int tl, int tr, int pos, T val) {
        if(tl == tr) {
            tree[node] = val;
        } else {
            int mid = (tl + tr) / 2;
            if(tl <= pos && pos <= mid)
                update(2*node, tl, mid, pos, val);
            else
                update(2*node+1, mid+1, tr, pos, val);
            tree[node] = combine(tree[2*node], tree[2*node+1]);
        }
    }
};

int main() {
    setIO();

    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    SegTree<ll, int> tree(v);

    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << tree.query(1, 0, n-1, a, b) << '\n';
    }

    return 0;
}