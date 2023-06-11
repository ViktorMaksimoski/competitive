#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int LOG = 20;
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

    ll n, ans = 0, div = 0;
    cin >> n;

    vector<ll> v(n);
    for(ll &x : v) cin >> x;

    for(ll &x : v) {
        ll cnt = 1;

        for(ll i=2; i<1LL*sqrt(2*x); i++) {
            if( (x - 1LL * (i * (i-1) / 2)) % i == 0 ) cnt++;
        }

        if(cnt == div) ans = min(ans, x);
        else if(cnt > div) ans = x, div = cnt;
    }

    cout << ans << " " << div << '\n';
    return 0;
}