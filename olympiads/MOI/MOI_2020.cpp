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
    vector<int> tree, lazy;

    SegTree(int _n) {
        n = _n;
        tree.resize(4*n+5);
        lazy.resize(4*n+5);
    }

    void push(int u, int tl, int tr) {
        if(lazy[u] == 0) return ;
        tree[u] += lazy[u];

        if(tl != tr) {
            lazy[2*u] += lazy[u];
            lazy[2*u+1] += lazy[u];
        }

        lazy[u] = 0;
    }

    void update(int u, int tl, int tr, int l, int r, int val) {
        push(u, tl, tr);
        if(tl > tr || l > tr || tl > r) return ;

        if(l <= tl && tr <= r) {
            lazy[u] += val;
            push(u, tl, tr);
            return ;
        }

        int tm = (tl + tr) / 2;
        update(2*u, tl, tm, l, r, val);
        update(2*u+1, tm+1, tr, l, r, val);
        tree[u] = max(tree[2*u], tree[2*u+1]);
    }

    int query(int u, int tl, int tr, int l, int r) {
        if(tl > tr || l > tr || tl > r) return 0;
        push(u, tl, tr);
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return max(
            query(2*u, tl, tm, l, r),
            query(2*u+1, tm+1, tr, l, r)
        );
    }

    void update(int l, int r, int val) { update(1, 0, n-1, l, r, val); }
    int query(int p) { return query(1, 0, n-1, 0, p); }
};  

int32_t main() {
    setIO();

    int n, ans = 0;
    cin >> n;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    SegTree tree(n+10);
    map<int, vector<int> > mp;

    for(int i=0; i<n; i++) {
        if(!mp[v[i]].empty()) {
            if(mp[v[i]].size() == 1) tree.update(0, mp[v[i]][mp[v[i]].size()-1], 1);
            else tree.update(mp[v[i]][mp[v[i]].size()-2]+1, mp[v[i]][mp[v[i]].size()-1], 1);

            if(mp[v[i]].size() >= 2) {
                if(mp[v[i]].size() == 2) tree.update(0, mp[v[i]][mp[v[i]].size()-2]-1, -1);
                else tree.update(mp[v[i]][mp[v[i]].size()-3], mp[v[i]][mp[v[i]].size()-2]-1, -1);
            }
        }

        mp[v[i]].push_back(i);
        ans = max(ans, tree.query(i-1));
    }

    cout << ans << '\n';
    return 0;
}