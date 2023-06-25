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

ll dp[1 << 20];
vector<int> v;
int n;

void to_binary(int n) {
    vector<int> bits;
    while(n > 0) {
        bits.push_back(n % 2);
        n /= 2;
    }

    cout << "bin: ";
    for(int i=bits.size()-1; i>=0; i--)
        cout << bits[i];
    cout << '\n';
}

ll solve(int mask, int round) {
    if(mask == (1 << n) - 1) return 0;
    if(dp[mask] > 0) return dp[mask];

    ll ans = 0;
    // if(mask == 0) cout << "bin: " << mask << '\n';
    // else to_binary(mask);

    for(int i=0; i<n; i++) {
        if(mask & (1 << i)) continue;
        for(int j=i+1; j<n; j++) {
            if(mask & (1 << j)) continue;
            
            int newMask = mask;
            newMask |= (1 << i);
            newMask |= (1 << j);
            ll res = __gcd(v[i], v[j]) * round;
            ans = max(ans, solve(newMask, round + 1) + res);
        }
    }

    dp[mask] = ans;
    return ans;
}

int main() {
    setIO();

    cin >> n;
    v.resize(n);
    for(int &x : v) cin >> x;
    memset(dp, 0, sizeof(dp));
    
    cout << solve(0, 1) << '\n';
    return 0;
}