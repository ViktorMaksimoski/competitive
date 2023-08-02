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
    long long n,x;
        cin >> n >> x;
        vector<long long>a(n),b(n),c(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }
        for (int i = 0; i < n; i++){
            cin >> c[i];
        }
        long long num = 0;
        for (int i = 0; i < n; i++){
            if ((a[i] ^ (x & a[i]))!= 0)break;
                 num |= a[i];
        }
        for (int i = 0; i < n; i++){
            if ((b[i] ^ (x & b[i])) != 0)break;
            num |= b[i];
        }
        for (int i = 0; i < n; i++){
            if ((c[i] ^ (x & c[i])) != 0)break;
            num |= c[i];
        }
        
        if (num != x)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
}

int main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}