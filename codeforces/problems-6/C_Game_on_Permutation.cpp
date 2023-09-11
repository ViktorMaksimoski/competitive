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

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n) : n(n), tree(4*n+5) {}

    void update(int u, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            tree[u] = val;
        } else {
            int tm = (tl + tr) / 2;
            if(pos <= tm)
                update(2*u, tl, tm, pos, val);
            else
                update(2*u+1, tm+1, tr, pos, val);
            tree[u] = max(tree[2*u], tree[2*u+1]);
        }
    }

    int query(int u, int tl, int tr, int l, int r) {
        if(tl > tr || l > tr || tl > r) return 0;
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return max(
            query(2*u, tl, tm, l, r),
            query(2*u+1, tm+1, tr, l, r)
        );
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

void solve() {
    int n;
    cin >> n;
    int ans = 0;

    SegTree tree(n+1);
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        int curr = tree.query(0, x-1);
        tree.update(x, curr + 1);

        ans += (curr + 1 == 2);
    }

    cout << ans << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}