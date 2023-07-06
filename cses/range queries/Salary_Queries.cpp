#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<long long, long long>
#define debug(x) cout << #x << " = " << x << endl
#define pb push_back
#define eb emplace_back
#define uniq(x) x.erase(unique(all(x)), x.end())
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;
 
void setIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}
 
struct Query {
    char type;
    int a, b;
};

struct SegTree {
    int n;
    vector<ll> tree;

    SegTree(int n) {
        this->n = n;
        tree.resize(4*n + 5, 0);
    }

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

    ll query(int u, int tl, int tr, int l, int r) {
        if(l > r) return 0;
        if(l == tl && tr == r) return tree[u];
        int tm = (tl + tr) / 2;
        return query(2*u, tl, tm, l, min(tm, r))
        + query(2*u+1, tm+1, tr, max(tm+1, l), r);
    }

    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

int main() {
    setIO();

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int &x : v) cin >> x;
    vector<int> v2 = v;

    vector<Query> ask(k);
    for(Query &q : ask) {
        cin >> q.type >> q.a >> q.b;
        if(q.type == '!') v2.pb(q.b);
        else v2.pb(q.a), v2.pb(q.b);
    }

    sort(all(v2));
    uniq(v2);

    int cnt = 0;
    unordered_map<int, int> comp;
    for(int &x : v2) comp[x] = cnt++;

    SegTree tree(sz(v2));
    for(int &x : v)
        tree.update(comp[x], 1);

    for(Query &q : ask) {
        if(q.type == '!') {
            tree.update(comp[v[q.a-1]], -1);
            v[q.a-1] = q.b;
            tree.update(comp[v[q.a-1]], 1);
        } else {
            cout << tree.query(comp[q.a], comp[q.b]) << '\n';
        }
    }

    return 0;
}