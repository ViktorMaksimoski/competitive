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

void solve() {
    int n;
    cin >> n;
    vector<int> arr;
    vector<bool> good(n, false);
    bool g = true;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        
        if(i < 2) {
            good[i] = 1;
            arr.push_back(x);
            if(x < arr[0]) g = false;
        } else {
            if(g && x >= arr.back()) {
                good[i] = true;
                arr.push_back(x);
            }
            else if(g && x <= arr[0]) {
                good[i] = true;
                arr.push_back(x);
                g = false;
            } else if(!g && x <= arr[0] && x >= arr.back()) {
                good[i] = true;
                arr.push_back(x);
            }
        }
    }

    for(bool b : good) cout << b;
    cout << '\n';
}

int main() {
    setIO();

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}