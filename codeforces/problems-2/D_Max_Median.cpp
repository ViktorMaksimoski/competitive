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

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    int l=1, r=n, ans=0;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        vector<int> pref(n);
        for(int i=0; i<n; i++) {
            pref[i] = (v[i] >= mid ? 1 : -1);

            if(i > 0) pref[i] += pref[i-1];
        }

        int mn=0, diff = 0;
        for(int i=m-1; i<n; i++) {
            mn = min(mn, pref[i-m]);
            diff = max(diff, pref[i] - mn);
        }

        if(diff > 0) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}