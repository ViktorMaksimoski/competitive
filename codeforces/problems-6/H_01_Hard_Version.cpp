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
    int pairs;
    int zero;
    int one;

    Node(int a=0, int b=0, int c=0) : pairs(a), zero(b), one(c) {}

    Node operator+(Node &b) {
        Node ans;

        ans.pairs = pairs + b.pairs + min(zero, b.one);
        ans.zero = zero - min(zero, b.one) + b.zero;
        ans.one = one + b.one - min(zero, b.one);

        return ans;
    }
};

struct SegTree {
    int n;
    string s;
    vector<Node> tree;

    SegTree(string const &t) {
        n = sz(t);
        s = t;
        tree.resize(4*n+5, 0);
        build(1, 0, n-1);
    }

    void build(int u, int tl, int tr) {
        if(tl == tr) {
            if(s[tl] == '0') {
                tree[u] = Node{0, 1, 0};
            } else {
                tree[u] = Node{0, 0, 1};
            }
        } else {
            int tm = (tl + tr) / 2;
            build(2*u, tl, tm);
            build(2*u+1, tm+1, tr);
            tree[u] = tree[2*u] + tree[2*u+1];
        }
    }

    void update(int u, int tl, int tr, int pos) {
        if(tl == tr) {
            if(s[pos] == '0') {
                s[pos] = '1';
                tree[u] = Node{0, 0, 1};
            } else {
                s[pos] = '0';
                tree[u] = Node{0, 1, 0};
            }
        } else {
            int tm = (tl + tr) / 2;
            if(pos <= tm)
                update(2*u, tl, tm, pos);
            else
                update(2*u+1, tm+1, tr, pos);
            tree[u] = tree[2*u] + tree[2*u+1];
        }
    }

    Node query(int u, int tl, int tr, int l, int r) {
        if(tl > tr || l > tr || tl > r) return Node{0, 0, 0};
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        Node a = query(2*u, tl, tm, l, r);
        Node b = query(2*u+1, tm+1, tr, l, r);
        Node res = a + b;
        return res;
    }

    void update(int pos) {
        update(1, 0, n-1, pos);
    }

    Node query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

int32_t main() {
    setIO();

    string s;
    cin >> s;

    int q;
    cin >> q;
    SegTree tree(s);

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int a;
            cin >> a;
            tree.update(a-1);
        } else {
            int a, b;
            cin >> a >> b;
            cout << (b - a + 1) - 2 * tree.query(a-1, b-1).pairs << '\n';
        }
    }

    return 0;
}