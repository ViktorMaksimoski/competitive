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
    ll ans = -1;
    vector<int> v;
    vector<ll> tree;

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

    void find(int u, int tl, int tr, int val, int pos) {
        if(tree[u] < val) return ;
        if(ans >= 0 || tr < pos) return ;

        if(tl == tr && tree[u] >= val) {
            ans = tl;
            return ;
        }

        int tm = (tl + tr) / 2;
        find(2*u, tl, tm, val, pos);
        find(2*u+1, tm+1, tr, val, pos);
    }

    ll find(int a, int b) {
        ans = -1;
        find(1, 0, n-1, a, b);
        return ans;
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
            int a, b;
            cin >> a >> b;
            cout << tree.find(a, b) << '\n';
        }
    }

    return 0;
}