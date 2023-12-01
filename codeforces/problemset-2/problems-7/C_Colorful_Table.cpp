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

struct Node {
    int mx, mn;
};

struct SegTree {
    int n;
    vector<int> v;
    vector<Node> tree;

    Node combine(Node a, Node b) {
        Node res;
        res.mx = max(a.mx, b.mx);
        res.mn = min(a.mn, b.mn);
        return res;
    }

    SegTree(vector<int> &_v) {
        v = _v;
        n = sz(v);
        tree.resize(4*n+5, Node{0, int(1e9)});
        build(1, 0, n-1);
    }

    void build(int u, int tl, int tr) {
        if(tl == tr) {
            tree[u] = {v[tl], v[tl]};
        } else {
            int tm = (tl + tr) / 2;
            build(2*u, tl, tm);
            build(2*u+1, tm+1, tr);
            tree[u] = combine(tree[2*u], tree[2*u+1]);
        }
    }

    Node query(int u, int tl, int tr, int l, int r) {
        if(tl > tr || tl > r || l > tr) return Node{0, int(1e9)};
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return combine(
            query(2*u, tl, tm, l, r),
            query(2*u+1, tm+1, tr, l, r)
        );
    }

    int getMax(int l, int r) {
        return query(1, 0, n-1, l, r).mx;
    }

    int getMin(int l, int r) {
        return query(1, 0, n-1, l, r).mn;
    }

};

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    vector<vector<int> > pos(k+1);
    for(int i=0; i<n; i++) {
        cin >> v[i];
        pos[v[i]].push_back(i);
    }

    SegTree tree(v);
    vector<int> ans(k+1);
    for(int i=1; i<=k; i++) {
        if(pos[i].size() == 0) {
            ans[i] = 0;
            continue;
        }
        
        int top=0;
        int l=0, r=n-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(tree.getMax(l, mid) >= i) {
                top = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        int bottom = 0;
        l=0, r=n-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(tree.getMax(mid, r) >= i) {
                bottom = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

        ans[i] = 2 * (bottom - top + 1);
    }

    for(int i=1; i<=k; i++) cout << ans[i] << " ";
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