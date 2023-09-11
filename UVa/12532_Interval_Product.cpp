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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct Node {
    int pos;
    int zero;
    int neg;

    Node() : pos(0), zero(0), neg(0) {}

    Node operator+(Node &b) {
        Node ans;

        ans.pos = pos + b.pos;
        ans.zero = zero + b.zero;
        ans.neg = neg + b.neg;

        return ans;
    }
};

struct SegTree {
    int n;
    vector<int> v;
    vector<Node> tree;

    SegTree(vector<int> const &_v) {
        n = sz(_v);
        v = _v;
        tree.resize(4*n+5);
        build(1, 0, n-1);
    }

    void build(int u, int tl, int tr) {
        if(tl == tr) {
            if(v[tl] == 0) tree[u].zero = 1;
            if(v[tl] > 0) tree[u].pos = 1;
            if(v[tl] < 0) tree[u].neg = 1;
        } else {
            int tm = (tl + tr) / 2;
            build(2*u, tl, tm);
            build(2*u+1, tm+1, tr);
            tree[u] = tree[2*u] + tree[2*u+1];
        }
    }

    void update(int u, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            tree[u].neg = 0;
            tree[u].zero = 0;
            tree[u].pos = 0;
            if(val == 0) tree[u].zero = 1;
            if(val > 0) tree[u].pos = 1;
            if(val < 0) tree[u].neg = 1;
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

    Node query(int u, int tl, int tr, int l, int r) {
        if(tl > tr || l > tr || tl > r) {
            Node node;
            node.neg = 0;
            node.pos = 0;
            node.zero = 0;
            return node;
        }
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        Node a = query(2*u, tl, tm, l, r);
        Node b = query(2*u+1, tm+1, tr, l, r);
        Node ans = a + b;
        return ans;
    }

    char query(int l, int r) {
        Node ans = query(1, 0, n-1, l, r);
        if(ans.zero > 0) return '0';
        if(ans.neg % 2 == 1) return '-';
        return '+';
    }
};

int32_t main() {
    setIO();

    int n, q;
    
    while(cin >> n >> q) {
        vector<int> v(n);
        for(int &x : v) cin >> x;

        SegTree tree(v);

        while(q--) {
            char t;
            cin >> t;

            if(t == 'C') {
                int a, b;
                cin >> a >> b;
                tree.update(a-1, b);
            } else {
                int a, b;
                cin >> a >> b;
                cout << tree.query(a-1, b-1);
            }
        }
        cout << '\n';
    }

    //cout << "HA\n";
    return 0;
}