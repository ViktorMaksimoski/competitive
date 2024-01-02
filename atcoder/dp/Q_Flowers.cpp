#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct BIT {
    int n;
    vector<ll> tree;

    BIT(int _n) : n(_n+5), tree(_n+60) {}

    void update(int p, ll v) {
        for(p++; p<n; p+=p&-p) tree[p] = max(tree[p], v); 
    }

    ll query(int p) {
        ll ans = 0;
        for(p++; p>0; p-=p&-p) ans = max(ans, tree[p]);
        return ans;
    }
};

int32_t main() {
    int n;
    cin >> n;
    vector<int> h(n), a(n);

    for(int &x : h) cin >> x;
    for(int &x : a) cin >> x;

    vector<ll> dp(n, 0);
    BIT bit(n+1);
    for(int i=0; i<n; i++) {
        dp[i] = bit.query(h[i]) + a[i];
        bit.update(h[i], dp[i]);
    }

    cout << bit.query(n) << '\n';
    return 0;
}