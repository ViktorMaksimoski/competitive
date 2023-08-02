#include <bits/stdc++.h>
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

struct Node {
    Node *lc, *rc;
    ll sum = 0;

    Node(ll sum) : sum(sum), lc(nullptr), rc(nullptr) {}
    Node(Node* lc, Node* rc) : sum(0), lc(lc), rc(rc) {
        if(lc) sum += lc->sum;
        if(rc) sum += rc->sum;
    }

    ~Node() {
        delete lc;
        delete rc;
    }
};

vector<int> v;

Node* build(int l, int r) {
    if(l == r) 
        return new Node(v[l]);
    int m = (l + r) / 2;
    return new Node(build(l, m), build(m+1, r));
}

ll query(Node* u, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l == tl && tr == r) return u->sum;
    int tm = (tl + tr) / 2;
    return query(u->lc, tl, tm, l, min(tm, r))
    + query(u->rc, tm+1, tr, max(tm+1, l), r);
}

Node* update(Node* u, int tl, int tr, int pos, int val) {
    if(tl == tr)
        return new Node(val);
    int tm = (tl + tr) / 2;
    if(pos <= tm)
        return new Node(
            update(u->lc, tl, tm, pos, val),
            u->rc
        );
    else
        return new Node(
            u->lc,
            update(u->rc, tm+1, tr, pos, val)
        );
}

int main() {
    setIO();

    int n, q;
    cin >> n >> q;
    
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.pb(x);
    }

    vector<Node*> roots;
    roots.pb(build(0, n-1));

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
           int a, b;
           cin >> a >> b;
           roots.pb(update(
            roots.back(),
            0,
            n-1,
            a-1,
            b
           ));
        } else {
            int a, b, c;
            cin >> a >> b >> c;
            ll res = query(roots[a], 0, n-1, b-1, c-1);
            cout << res << '\n';
        }
    }

    return 0;
}