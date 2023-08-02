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

    int t;
    cin >> t;
    vector<int> sieve(int(3*1e4), 0);
    for(int i=2; i<=int(3*1e4); i++) {
        if(sieve[i]) continue;
        for(int j=i*i; j<=int(3*1e4); j += i) sieve[j] = 1;
    }
    
    while(t--) {
        int d;
        cin >> d;
        ll div1=1, div2=1;

        for(int i=d+1; i<=int(3*1e4); i++) {
            if(!sieve[i]) {
                div1 = i;
                break;
            }
        }

        for(int i=div1+d; i<=int(3*1e4); i++) {
            if(!sieve[i]) {
                div2 = i;
                break;
            }
        }

        cout << div1 * div2 << '\n';
    }

    return 0;
}