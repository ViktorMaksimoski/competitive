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

    int t;
    cin >> t;

    while(t--) {
        ll n, k;
        cin >> n >> k;

        ll l=1, r=1e12, ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;

            if(mid - mid/n >= k) {
                r = mid - 1;
                ans = mid;
            } else l = mid + 1;
        }
        cout << ans << '\n';
    }

    return 0;
}