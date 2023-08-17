#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct SegTree {
    int n;
    vector<int> v;
    vector<ll> tree;

    void init(vector<int> const &_v) {
        n = _v.size();
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
            tree[u] = max(tree[2*u], tree[2*u+1]);
        }
    }

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

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }

    ll get(int u) {
        return tree[u];
    }
};

struct DSU {
    int n, comp;
    vector<int> par, size, total;
    SegTree tree;

    DSU(int _n, vector<int> const& pop) {
        comp = _n;
        n = _n+1;
        size.resize(n, 1);
        par.resize(n);
        total.resize(n);
        for(int i=0; i<n; i++) par[i] = i;
        for(int i=0; i<n; i++) total[i] = pop[i];
        tree.init(total);
    }


    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    int getComp() {
        return comp;
    }

    int getTotal(int x) {
        x = find(x);
        return total[x];
    }

    bool uni(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return 0;

        if(size[a] < size[b]) swap(a, b);
        total[a] += total[b];
        total[b] = 0;
        tree.update(a, total[a]);
        tree.update(b, total[b]);
        size[a] += size[b];
        par[b] = a;
        return 1;
    }

    ll getMax() {
        return tree.get(1); 
    }

    void updateTotal(int x, int v) {
        x = find(x);
        total[x] += v;
        tree.update(x, total[x]);
    }
};

int32_t main() {
    setIO();

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int> > poplist(n+1);
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        poplist[i].push_back(x);
    }

    vector<pii> edges(m+1);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        edges[i+1] = { a, b };
    }

    bool bad[m+1];
    memset(bad, 0, sizeof(bad));
    vector<vector<int> > queries;

    for(int i=0; i<q; i++) {
        char ch;
        cin >> ch;

        if(ch == 'P') {
            int a, b;
            cin >> a >> b;
            queries.push_back({ 1, a, b });
            poplist[a].push_back(b);
        } else {
            int a;
            cin >> a;
            bad[a] = 1;
            queries.push_back({ 2, a });
        }
    }

    vector<int> pop(n+1);
    for(int i=1; i<=n; i++) pop[i] = poplist[i].back();
    DSU dsu(n, pop);
    
    //build roads that are not going to be destroyed first
    for(int i=1; i<=m; i++) {
        if(bad[i]) continue;
        dsu.uni(edges[i].first, edges[i].second);
    }

    //pointers to curr population of city
    vector<int> ptr(n+1);
    for(int i=1; i<=n; i++) ptr[i] = poplist[i].size() - 1;

    reverse(all(queries));
    vector<int> ans(q);
    for(int i=0; i<q; i++) {
        ans[i] = dsu.getMax();

        if(queries[i][0] == 2) {
            dsu.uni(edges[queries[i][1]].first, edges[queries[i][1]].second);
        } else {
            int curr = poplist[queries[i][1]][ptr[queries[i][1]]];
            dsu.updateTotal(queries[i][1], -curr);
            ptr[queries[i][1]]--;
            curr = poplist[queries[i][1]][ptr[queries[i][1]]];
            dsu.updateTotal(queries[i][1], curr);
        }
    }

    for(int i=q-1; i>=0; i--)
        cout << ans[i] << '\n';
    return 0;
}