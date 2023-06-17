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
    setIO("haybales");

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int &x : v) cin >> x; 

    sort(v.begin(), v.end());
    while(k--) {
        int a, b;
        cin >> a >> b;
        cout << upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a) << '\n';
    }

    return 0;
}