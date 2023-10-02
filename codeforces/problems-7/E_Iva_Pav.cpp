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
    vector<int> v;
    vector<int> tree;

    SegTree(vector<int> &_v) {
        n = sz(_v);
        v = _v;
        tree.resize(4*n+5);
        build(1, 0, n-1);
    } 

    void build(int u, int tl, int tr) {
        if(tl == tr) {
            tree[u] = v[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(2*u, tl, tm);
            build(2*u+1, tm+1, tr);
            tree[u] = tree[2*u] & tree[2*u+1];
        }
    }

    int query(int u, int tl, int tr, int l, int r) {
        if(tl > tr || l > tr || tl > r) return (1 << 30) - 1;
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return query(2*u, tl, tm, l, r) &
        query(2*u+1, tm+1, tr, l, r);
    }

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    int q;
    cin >> q;
    SegTree tree(v);
    while(q--) {
        int k, l;
        cin >> l >> k;

        int lp=l-1, rp=n-1;
        int ans = -1;

        while(lp <= rp) {
            int mid = (lp + rp) / 2;

            if(tree.query(l-1, mid) >= k) {
                ans = mid;
                lp = mid + 1;
            } else {
                rp = mid - 1;
            }
        }

        cout << (ans == -1 ? ans : ans + 1) << " ";
    }
    cout << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}