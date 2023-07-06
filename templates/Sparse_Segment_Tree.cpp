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
    int sum, lazy;
    Node *l, *r;
 
    Node() {
        sum = 0, lazy = 0;
        l = nullptr, r = nullptr;
    }
 
    ~Node() {
        delete l;
        delete r;
    }
 
    void extend(int tl, int tr) {
        if(tl == tr) return ;
        if(this->l == nullptr) this->l = new Node();
        if(this->r == nullptr) this->r = new Node();
    }
 
    void push(int tl, int tr) {
        if(this->lazy == 0) return ;
        this->sum = (tr - tl + 1) * this->lazy;
 
        if(tl != tr) {
            extend(tl, tr);
            this->l->lazy = this->lazy;
            this->r->lazy = this->lazy;
        }
 
        this->lazy = 0;
    }
};

void updateLazy(Node *root, int tl, int tr, int l, int r, short val) {
    root->push(tl, tr);
    if(tl > r || l > tr || tl > tr) return ;
 
    if(l <= tl && tr <= r) {
        root->lazy = val;
        root->push(tl, tr);
        return ;
    }
 
    root->extend(tl, tr);
    int tm = (tl + tr) / 2;
    updateLazy(root->l, tl, tm, l, r, val);
    updateLazy(root->r, tm+1, tr, l, r, val);
    root->sum = root->l->sum + root->r->sum;
}

void updateSingle(Node *root, int tl, int tr, int pos, int val) {
    if(tl > pos || pos > tr) return ;

    if(tl == tr && tl == pos) {
        root->sum = val;
        return ;
    }

    root->extend(tl, tr);
    int tm = (tl + tr) / 2;
    if(pos <= tm)
        updateSingle(root->l, tl, tm, pos, val);
    else
        updateSingle(root->r, tm+1, tr, pos, val);
    root->sum = root->l->sum + root->r->sum;
}

ll query(Node *root, int tl, int tr, int l, int r) {
    if(r < tl || tr < l) return 0;
    root->push(tl, tr);
 
    if(l <= tl && tr <= r) return root->sum;
 
    root->extend(tl, tr);
    auto tm = (tl + tr) / 2;

    return query(root->l, tl, tm, l, r) +
    query(root->r, tm+1, tr, l, r);
}

int main() {
    setIO();

    int q;
    cin >> q;
 
    ll c = 0;
    Node *root = new Node();
    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
 
        if(t == 1) {
            ll res = query(root, 1, 1e9, a+c, b+c);
            cout << res << '\n';
            c = res;
        } else {
            updateLazy(root, 1, 1e9, a+c, b+c, 1);
        }
    }

    return 0;
}