#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
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

struct SegTree {
    int n;
    vector<ll> tree;

    SegTree(int n) : n(n), tree(4*n+5, 0) {}

    void add(int u, int tl, int tr, int l, int r, int val) {
        if(l > tr || tl > r) return ;
        if(l <= tl && tr <= r) {
            tree[u] += val;
            return ;
        }
        int tm = (tl + tr) / 2;
        add(2*u, tl, tm, l, r, val);
        add(2*u+1, tm+1, tr, l, r, val);
    }

    ll get(int u, int tl, int tr, int pos) {
        if(tl == tr) return tree[u];
        int tm = (tl + tr) / 2;
        ll sum = 0;
        if(pos <= tm)
            sum += get(2*u, tl, tm, pos);
        else if(pos <= tr)
            sum += get(2*u+1, tm+1, tr, pos);
        return sum + tree[u];
    }

    void add(int l, int r, int val) {
        add(1, 0, n-1, l, r, val);
    }

    ll get(int pos) {
        return get(1, 0, n-1, pos); 
    }
};

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;
    
    SegTree tree(n);
    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            tree.add(a, b-1, c);
        } else {
            int a;
            cin >> a;
            cout << tree.get(a) << '\n';
        }
    }

    return 0;
}