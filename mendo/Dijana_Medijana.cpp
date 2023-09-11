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
    vector<ll> tree;

    SegTree(int _n): n(_n), tree(4*_n+5, 0) {} 

    void update(int u, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            tree[u] += val;
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

    int find(int u, int tl, int tr, ll x) {
        if(tl == tr) return tl;
        int tm = (tl + tr) / 2;
        if(x <= tree[2*u])
            return find(2*u, tl, tm, x);
        return find(2*u+1, tm+1, tr, x - tree[2*u]);
    }

    int find(ll x) {
        return find(1, 0, n-1, x);
    }
};

int32_t main() {
    setIO();

    int q;
    cin >> q;

    vector<pii> query(q);
    set<int> s;
    for(int i=0; i<q; i++) {
        cin >> query[i].first >> query[i].second;
        s.insert(query[i].first);
    }

    vector<int> v(all(s));
    ll total = 0;
    SegTree tree(sz(v));

    for(pii &x : query) {
        int pos = lower_bound(all(v), x.first) - v.begin();
        //cout << pos << '\n';
        
        tree.update(pos, x.second);
        total += x.second;

        ll median = 0;
        if(total & 1) median = total / 2 + 1;
        else median = total / 2;

        cout << v[tree.find(median)] << '\n';
    }

    return 0;
}