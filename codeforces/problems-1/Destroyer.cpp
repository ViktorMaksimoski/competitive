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

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> occ;
    for(int &x : v) {
        cin >> x;
        occ[x]++;
    }

    sort(v.begin(), v.end());
    if(n == 1 && v[0] > 0) {
        cout << "NO\n";
        return ;
    } else if(n == 1 && v[0] == 0) {
        cout << "YES\n";
        return ;
    }

    for(int i=1; i<n; i++) {
        if(occ[v[i]] > occ[v[i]-1] && v[i] > 0) {
            cout << "NO\n";
            return ;
        }
    }

    cout << "YES\n";
}

int main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve(); 

    return 0;
}