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
    vector<ll> v;
    vector<ull> tree;

    SegTree(vector<ll> const &v) {
        this->n = sz(v);
        this->v = v;
        tree.resize(3*sz(v) + 5);
        build(1, 0, n-1);
    }

    void build(int node, int l, int r) {
        if(l == r) {
            tree[node] = v[l];
        } else {
            int mid = (l + r) / 2;
            build(2*node, l, mid);
            build(2*node+1, mid+1, r);
            tree[node] = tree[2*node] ^ tree[2*node+1];
        }
    }

    ull query(int node, int tl, int tr, int l, ll r) {
        if(l > r) return 0;
        if(l == tl && r == tr) return tree[node];

        int tm = (tl + tr) / 2;
        return query(2*node, tl, tm, l, min(r, 1ll*tm)) ^ query(2*node+1, tm+1, tr, max(l, tm+1), r);
    }

    void update(int node, int l, int r, int pos, ll val) {
        if(l == r) {
            tree[node] = val;
            v[l] = val;
        } else {
            int mid = (l + r) / 2;
            if(l <= pos && pos <= mid)
                update(2*node, l, mid, pos, val);
            else
                update(2*node+1, mid+1, r, pos, val);
            tree[node] = tree[2*node] ^ tree[2*node+1];
        }
    }
};

int main() {
    setIO();

    int n, q;
    cin >> n >> q;

    vector<ll> v(n), even, odd;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        if(i % 2 == 1) even.pb(v[i]);
        else odd.pb(v[i]);
    }

    SegTree tree1(odd), tree2(even);
    while(q--) {
        int t, a;
        ll b;
        cin >> t >> a >> b;

        if(t == 1) {
            if(a % 2 == 1)
                tree1.update(1, 0, sz(odd)-1, a/2, b);
            else
                tree2.update(1, 0, sz(even)-1, a/2-1, b);
        } else {
            if((b - a + 1) % 2 == 0) cout << 0 << '\n';
            else {
                if(a % 2 == 1)
                    cout << tree1.query(1, 0, sz(odd)-1, a/2, b/2) << '\n';
                else
                    cout << tree2.query(1, 0, sz(even)-1, a/2-1, b/2-1) << '\n';
            }
        }
    }

    return 0;
}