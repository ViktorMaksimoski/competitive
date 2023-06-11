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
    setIO();

    int n, k;
    map<int, int> occ;
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        occ[x]++;
    }

    for(auto &x : occ) {
        if(x.second % k > 0) {
            cout << x.first << '\n';
        }
    }

    return 0;
}