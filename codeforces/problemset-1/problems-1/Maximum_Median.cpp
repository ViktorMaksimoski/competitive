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

    int n, k;
    ll ans = 0;
    cin >> n >> k;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    sort(v.begin(), v.end());

    int l=0, r=k;
    while(l <= r) {
        int mid = (l + r) / 2;
        int newMedian = v[n/2] + mid;
        ll sum = 0;

        for(int i=n/2+1; i<n; i++) {
            if(newMedian > v[i]) sum += (newMedian - v[i]);
            if(sum > k - mid) break;
        }

        if(sum + mid <= k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << v[n/2] + ans << '\n';
    return 0;
}