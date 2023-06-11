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

ll bc[21][21];
ll binomial_coefficient(int n, int k) {
    if(k == n || k == 0)
        return 1;
    
}

int main() {
    setIO();

    ull ans = 0;
    int n, x, y, k;
    cin >> n >> x >> y >> k;
    memset(bc, -1, sizeof(bc));

    cout << ans << '\n';
    return 0;
}