#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 2e5 + 5;
using namespace std;
 
void setUSA(string name) {
     freopen( (name + ".in").c_str(), "r", stdin);
     freopen( (name + ".out").c_str(), "w", stdout);
}
 
void setIO(string name = "") {
     ios_base::sync_with_stdio(false);
     cout.tie(nullptr);
     cin.tie(nullptr);
     if(name != "") setUSA(name);
}
 
struct BIT {
    vector<ll> tree;
    int n;
 
    BIT(int x) {
        tree.resize(x);
        n = x;
    }
 
    BIT(vector<int> const &v) : BIT(v.size()) {
        for(int i=0; i<v.size(); i++)
            update(i, v[i]);
    }
 
    void update(int x, int d) {
        for(; x < n; x = x | (x + 1))
            tree[x] += d;
    }
 
    ll sum(int id) {
        ll s = 0;
 
        for(; id >= 0; id = (id & (id + 1)) - 1)
            s += tree[id];
        return s;
    }
 
    ll sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
};
 
int main() {
    setIO();
 
    int n, q;
    cin >> n >> q;
 
    vector<int> v(n);
    for(int &x : v) cin >> x;
 
    BIT tree(v);
 
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << tree.sum(a-1, b-1) << '\n';
    } 
 
    return 0;
}