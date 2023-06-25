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

void interactive(int l, int r, int k) {
    if(l == r) {
        cout << "! " << l << endl;
        return ;
    }

    int mid = l + (r - l) / 2;
    ll sum;
    cout << "? " << l << " " << mid << endl;
    cin >> sum;

    if((mid -l + 1) - sum >= k) {
        interactive(l, mid, k);
    } else {
        interactive(mid+1, r, k - ((mid - l + 1) - sum));
    }
}

int main() {
    setIO();

    int n, t, k;
    cin >> n >> t >> k;

    interactive(1, n, k);

    return 0;
}