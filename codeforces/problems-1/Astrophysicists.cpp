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

void solve() {
    ll n, k, g;
    cin >> n >> k >> g;
    ll to_pay = k * g;

    if(to_pay - 1LL * (((g+1)/2)-1) * n < 0) {
        cout << to_pay << '\n';
    } else {
        ll d1 = to_pay - 1ll * ((g+1)/2 - 1) * n + g - 1;
        cout << to_pay - (d1 / g) * g * 1ll << '\n'; 
    }
    
}

int main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve(); 

    return 0;
}