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

//for each node we save its sum, lazy, and it's children, if any
struct Node {
    ll sum=0, l, r, lazy=0;
    Node *lc, *rc;

    Node(ll l, ll r) : l(l), r(r), lc(nullptr), rc(nullptr) {}
    ~Node() {
        delete lc;
        delete rc;
    }

    void update(ll pos, ll val) {
        this->sum += val;
        if(l == r || l > pos || r < pos) return ;

        int tm = (l + r) / 2;
        if(pos <= tm) {
            if(!lc) lc = new Node(l, tm);
            lc->update(pos, val);
        } else {
            if(!rc) rc = new Node(tm+1, r);
            rc->update(pos, val);
        }
    }

    void push() {
        if(lazy == 0) return ;
        sum = (r - l + 1) * lazy;

        if(l != r) {
            if(lc) lc->lazy = lazy;
            if(rc) rc->lazy = lazy;
        }

        lazy = 0;
    }

    ll query(ll tl, ll tr) {
        if(l > tr || tl > r) return 0;
        push();
        if(tl <= l && r <= tr) return sum;
        ll res = 0;
        if(lc) res += lc->query(tl, tr);
        if(rc) res += rc->query(tl, tr);
        return res;
    }
};

int main() {
    setIO();

    Node *root = new Node(1, 1e9);

    int q;
    cin >> q;
    while(q--) {
        int t, a, b;
        cin >> t;

        if(t == 1) {
            cin >> a >> b;
            cout << root->query(a, b) << '\n';
        } else {
            cin >> a >> b;
            root->update(a, b);
        }
    }

    return 0;
}