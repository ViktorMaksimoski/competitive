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

    SegTree(int n) : n(n), tree(4*n+5, 0) {}

    void update(int u, int tl, int tr, int pos) {
        if(tl == tr) {
            tree[u]++;
        } else {
            int tm = (tl + tr) / 2;
            if(pos <= tm)
                update(2*u, tl, tm, pos);
            else
                update(2*u+1, tm+1, tr, pos);
            tree[u] = tree[2*u] + tree[2*u+1];
        }
    }

    int query(int u, int tl, int tr, int l, int r) {
        if(tl > tr || l > tr || tl > r) return 0;
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return query(2*u, tl, tm, l, r)
        + query(2*u+1, tm+1, tr, l, r);
    }

    void update(int pos) {
        update(1, 0, n-1, pos);
    }

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

int32_t main() {
    setIO();
    setUSA("bphoto");

    int n;
    cin >> n;

    vector<int> v(n);
    set<int> s;

    for(int &x : v) cin >> x, s.insert(x);

    vector<int> comp(all(s));
    SegTree tree_left(n), tree_right(n);

    vector<int> dp_left(n, 0), dp_right(n, 0);

    for(int i=0; i<n; i++) {
        int pos = lower_bound(all(comp), v[i]) - comp.begin();
        dp_left[i] = tree_left.query(pos+1, n-1);
        tree_left.update(pos);
    }
    
    for(int i=n-1; i>=0; i--) {
        int pos = lower_bound(all(comp), v[i]) - comp.begin();
        dp_right[i] = tree_right.query(pos+1, n-1);
        tree_right.update(pos);
    }

    int ans = 0;
    for(int i=0; i<n; i++) 
        ans += (max(dp_left[i], dp_right[i]) > 2 * min(dp_left[i], dp_right[i]));

    cout << ans << '\n';
    return 0;
}