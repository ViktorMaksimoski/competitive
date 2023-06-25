#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

bool check(ll mid, ll n, ll k, ll m) {
    ll g = 0;
    while(g < n && k > 0) {
        ll y = (n - g) / mid;
        if(y < m) {
            ll left = ((n - g) + (m - 1)) / m;
            return left <= k;
        }

        ll days = min(k, (n - (mid * y) - g) / y + 1);

        g += (y * days);
        k -= days;

    }

    return (g >= n);
}

int main() {
    setIO("loan");

    ll n, k, m;
    ll ans = 0;
    cin >> n >> k >> m;

    ll l=1, r=1e12;
    while(l <= r) {
        auto mid = l + (r - l) / 2;
    
        if(check(mid, n, k, m)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}