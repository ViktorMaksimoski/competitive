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
    bool mat[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            char ch;
            cin >> ch;
            mat[i][j] = (ch == 'D' ? 1 : 0);
        }
    }
            

    ll dp[1 << n];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    for(int s=0; s < (1 << n); s++) {
        int pn = __builtin_popcount(s);

        for(int w=0; w<n; w++) {
            if(s & (1 << w)) continue;
            if(!mat[pn][w]) continue;

            dp[s | (1 << w)] += dp[s];
            dp[s | (1 << w)] %= mod;
        }
    }

    cout << dp[(1<<n)-1] % mod << '\n'; 
    return 0;
}