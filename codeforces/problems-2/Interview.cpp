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

void print(int a, int b) {
    cout << "? " << b-a+1;
    for(int i=a; i<=b; i++) {
        cout << " " << i;
    }
    cout << endl;
}

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    vector<ll> prefix(n+1, 0);
    for(int i=0; i<n; i++) {
        cin >> v[i];
        prefix[i+1] = v[i] + prefix[i];
    }

    int l=1, r=n;
    while(l <= r) {

        int mid = (l + r) / 2;
        print(l, mid);
        ll sum;
        cin >> sum;
        if(prefix[mid] - prefix[l-1] == sum - 1) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << "! " << ans << endl;
}

int main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve(); 

    return 0;
}