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

int main() {
    setIO();

    ll n;
    cin >> n;

    ll ans=0, l=1, r=n*n, p=0;
    
    while(l <= r) {
        ll mid = (l + r) / 2;
        p = 0;

        for(ll i=1; i<=n; i++) p += min(mid/i, n);

        if(p >= (n*n + 1) / 2) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}