#include <bits/stdc++.h>
#include <vector>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define pii pair<int, int>
#define pll pair<long long, long long>
#define debug(x) cout << #x << " = " << x << endl
#define pb push_back
#define eb emplace_back
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
    int pos;
    int val;
    bool important;
};

bool cmp(Query &a, Query &b) {
    if(a.pos == b.pos)
        return (a.important < b.important);
    return (a.pos < b.pos);
}

struct Node {
    int val = 0;
    Node *l, *r;
 
    Node(int val) : val(val), l(nullptr), r(nullptr) {}
    Node(Node *l, Node *r) : l(l), r(r), val(0) {
        if(l) val = max(val, l->val);
        if(r) val = max(val, r->val);
    }
};
 
Node* build(int l, int r) {
    if(l == r)
        return new Node(0);
    int m = (l + r) / 2;
    return new Node(
        build(l, m),
        build(m+1, r)  
    );
}
 
int query(Node *u, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(tl == l && r == tr) return u->val;
    int tm = (tl + tr) / 2;
    return max(
        query(u->l, tl, tm, l, min(tm, r)),
        query(u->r, tm+1, tr, max(l, tm+1), r)  
    );
}
 
Node* update(Node *u, int tl, int tr, int pos, int val) {
    if(tl == tr) return new Node(val);
    int tm = (tl + tr) / 2;
    if(pos <= tm)
        return new Node(
            update(u->l, tl, tm, pos, val), 
            u->r
        );
    else
        return new Node(
            u->l,
            update(u->r, tm+1, tr, pos, val)
        );
}
 

int main() {
    setIO();

    int n, q;
    cin >> n >> q;

    vector<Query> process;
    vector<pii> queries;
    vector<int> v2;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        process.pb(Query{i, x, 1});
        v2.pb(x);
    }

    for(int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        v2.pb(b);
        process.pb(Query{a, b, 0});
    }

    sort(all(v2));
    sort(all(process), cmp);
    uniq(v2);

    for(int &x : v2) cout << x << " ";
    cout << '\n';
    for(Query &qu : process)
        cout << qu.pos << ": " << qu.val << ", " << qu.important << '\n';

    vector<Node*> roots;
    roots.pb(build(0, sz(v2)-1));

    

    return 0;
}