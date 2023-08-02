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

    int n;
    cin >> n;
    vector<ll> prefix(n, 0);

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        if(i == 0) prefix[i] = x;
        else prefix[i] = x + prefix[i-1];
    }

    int q;
    cin >> q;

    while(q--) {
        int x;
        cin >> x;
        int ans = lower_bound(prefix.begin(), prefix.end(), x) - prefix.begin();
        cout << ans+1 << '\n';
    }

    return 0;
}