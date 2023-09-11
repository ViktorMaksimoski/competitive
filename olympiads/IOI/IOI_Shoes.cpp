#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n) : n(n), tree(4*n+5, 0) {}

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

    int query(int u, int tl, int tr, int l, int r) {
        if(tl > tr || l > tr || tl > r) return 0;
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return query(2*u, tl, tm, l, r)
        + query(2*u+1, tm+1, tr, l, r);
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

int64_t count_swaps(vector<int> S) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n = S.size() / 2;
    ll ans = 0;

    map<int, vector<int> > occ;
    map<int, int> ptr;
    vector<bool> vis(2*n, false);
    SegTree tree(2*n);

    for(int i=0; i<2*n; i++) {
        occ[S[i]].push_back(i);
        if(!ptr.count(S[i])) ptr[S[i]] = 0;
    }

    for(int i=0; i<2*n; i++) {
        if(vis[i]) continue;
        vis[i] = true;
        int to_pair_pos = occ[-S[i]][ptr[-S[i]]];
        vis[to_pair_pos] = true;

        if(S[i] < 0) ans += (to_pair_pos - i - 1);
        else ans += (to_pair_pos - i);
        
        ans -= tree.query(i, to_pair_pos);
        tree.update(to_pair_pos, 1);

        ptr[-S[i]]++;
        ptr[S[i]]++;
    }

    return ans;
}