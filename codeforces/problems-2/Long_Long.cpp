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

int sgn(int x) {
    if(x > 0) return 1;
    else if(x < 0) return -1;
    return 0;
}

void solve() {
    int n, pos=0, neg=0;
    ll mx = 0;
    cin >> n;
    vector<int> v(n);
    for(int &x : v)  {
        cin >> x;
        mx += abs(x);
        if(x > 0) pos++, x = 1;
        else if(x < 0) neg++, x = -1;
    }

    int posSegments = 0;
    int negSegments = 0;
    int i=0;
    for(i; i<n; i++) {
        
        int sign = v[i];
        if(i < n-1 && sign == 0) sign = v[i+1];
        for(int j=i; j<n; j++) {
            if(j == n-1 && (v[j] == sign || v[j] == 0)) {
                if(sign > 0) posSegments++;
                else if(sign < 0) negSegments++;
                //cout << i << " " << j << endl;
                i = j;
                break;
            }

            if(v[j] != 0 && v[j] != sign) {
                if(sign > 0) posSegments++;
                else if(sign < 0) negSegments++;
               // cout << i << " " << j-1 << endl;
                i = j-1;
                break;
            }
        }

    }
    
    cout << mx << " " << negSegments << '\n';
    //cout << "---------\n";
}  

int main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve(); 

    return 0;
}