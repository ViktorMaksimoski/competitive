#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <stack>
#include <cstring>
#include <chrono>
#include <random>
#include <numeric>
#include <bitset>
#include <array>

#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair
#define rep(i, a, b) for(int i=a; i<b; i++)
#define repr(i, a, b) for(int i=a; i>=b; i--)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<int> v;

struct Node {
    ll sum = 0;
    Node *lc, *rc;

    Node(ll sum) : sum(sum), lc(nullptr), rc(nullptr) {}
    Node(Node *lc, Node *rc) : sum(0), lc(lc), rc(rc) {
        if(lc) sum += lc->sum;
        if(rc) sum += rc->sum;
    }

    ~Node() {
        delete lc;
        delete rc;
    }
};

Node* build(int l, int r) {
    if(l == r)
        return new Node(v[l]);
    int m = (l + r) / 2;
    return new Node(build(l, m), build(m+1, r));
}

ll query(Node *root, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l == tl && r == tr) return root->sum;
    int tm = (tl + tr) / 2;
    return query(root->lc, tl, tm, l, min(r, tm))
    + query(root->rc, tm+1, tr, max(tm+1, l), r);
}

Node* update(Node* u, int tl, int tr, int pos, int val) {
    if(tl == tr) return new Node(val);
    int tm = (tl + tr) / 2;
    if(pos <= tm)
        return new Node(
            update(u->lc, tl, tm, pos, val),
            u->rc
        );
    return new Node(
        u->lc,
        update(u->rc, tm+1, tr, pos, val)
    );
}

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;
    v.resize(n);
    each(x, v) cin >> x;

    vector<Node*> roots;
    roots.pb(build(0, n-1));

    while(q--) {
        int t;
        cin >> t;
        
        if(t == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            roots[a-1] = update(roots[a-1], 0, n-1, b-1, c);
        } else if(t == 2) {
            int a, b, c;
            cin >> a >> b >> c;
            cout << query(roots[a-1], 0, n-1, b-1, c-1) << '\n';
        } else {
            int a;
            cin >> a;
            roots.pb(roots[a-1]);
        }
    }

    return 0;
}