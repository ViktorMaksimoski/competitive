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

    int n;
    cin >> n;
    vector<int> sieve(int(1e6+1), 0);
    for(int i=2; i<=int(1e6); i++) {
        if(sieve[i] > 0) continue;
        for(int j=i; j<=int(1e6); j+=i) sieve[j] = i;
    }

    while(n--) {
        int a;
        cin >> a;

        ll res = 1;

        while(a != 1) {
            int div = sieve[a];
            int cnt = 0;

            while(a % div == 0) {
                cnt++;
                a /= div;
            }

            res *= (cnt + 1);
        }

        cout << res << '\n';
    }

    return 0;
}