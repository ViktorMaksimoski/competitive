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
    int n, m;
    ll sumA = 0, sumB = 0;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &x : a) cin >> x, sumA += x;
    for(int &x : b) cin >> x, sumB += x;
    
    if(sumA > sumB) cout << "Tsondu\n";
    else if(sumA < sumB) cout << "Tenzing\n";
    else cout << "Draw\n";
}

int main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();
    return 0;
}