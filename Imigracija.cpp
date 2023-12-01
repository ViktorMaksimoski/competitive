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
using S = array<int, 3>;
using Q = array<int, 4>;
  
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
    vector<vector<pii> > v;
    vector<vector<pii> > tree;
    vector<vector<ll> > pref;
  
    SegTree(vector<vector<pii> > &_v) {
        n = sz(_v);
        v = _v;
        tree.resize(4*n+5);
        pref.resize(4*n+5);
        build(1, 0, n-1);
    }
  
    void build(int u, int tl, int tr) {
        if(tl == tr) {
            tree[u] = v[tl];
            for(int i=0; i<sz(v[tl]); i++) {
                pref[u].push_back(v[tl][i].second);
                if(i > 0) pref[u][i] += pref[u][i-1];
            }
        } else {
            int tm = (tl + tr) / 2;
            build(2*u, tl, tm);
            build(2*u+1, tm+1, tr);
            merge(all(tree[2*u]), all(tree[2*u+1]), back_inserter(tree[u]));
            for(int i=0; i<sz(tree[u]); i++) {
                pref[u].push_back(tree[u][i].second);
                if(i > 0) pref[u][i] += pref[u][i-1];
            }
        }
    }
  
    ll query(int u, int tl, int tr, int l, int r, int y1, int y2) {
        if(tl > tr || l > tr || tl > r) return 0;
  
        if(l <= tl && tr <= r) {
            if(sz(tree[u]) == 0) return 0;
            if(tree[u].back().first < y1) return 0;
            if(tree[u][0].first > y2) return 0;
            ll res = 0;
              
            int l=0, r=sz(tree[u])-1;
            int lp=0;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(tree[u][mid].first >= y1) lp = mid, r = mid - 1;
                else l = mid + 1;
            }
 
            l=lp, r=sz(tree[u])-1;
            int rp=lp;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(tree[u][mid].first <= y2) rp = mid, l = mid + 1;
                else r = mid - 1;
            }
 
            res += pref[u][rp];
            if(lp > 0) res -= pref[u][lp-1];
  
            return res;
        }
  
        int tm = (tl + tr) / 2;
        return query(2*u, tl, tm, l, r, y1, y2)
        + query(2*u+1, tm+1, tr, l, r, y1, y2);
    }
  
    ll query(int x1, int y1, int x2, int y2) {
        return query(1, 0, n-1, x1, x2, y1, y2);
    }
};
  
int32_t main() {
    setIO();
  
    int n;
    cin >> n;
    vector<S> v(n);
    set<int> by_x;
    for(S &x : v) {
        cin >> x[0] >> x[1] >> x[2];
        by_x.insert(x[0]);
    }
  
    int q;
    cin >> q;
    vector<Q> qus(q);
    for(Q &x : qus) {
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        by_x.insert(x[0]);
        by_x.insert(x[2]);
    }
  
    vector<int> comp(all(by_x));
    vector<vector<pii> > on_pos(sz(comp));
    for(S &x : v) {
        x[0] = lower_bound(all(comp), x[0]) - comp.begin();
        on_pos[x[0]].push_back({ x[1], x[2] });
    }
  
    for(Q &x : qus) {
        x[0] = lower_bound(all(comp), x[0]) - comp.begin();
        x[2] = lower_bound(all(comp), x[2]) - comp.begin();
    }
  
    for(int i=0; i<sz(on_pos); i++)
        sort(all(on_pos[i]));
      
    SegTree tree(on_pos);
    for(Q &x : qus)
        cout << tree.query(x[0], x[1], x[2], x[3]) << '\n';
    return 0;
}