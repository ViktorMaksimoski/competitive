#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 998244353;
const int MAXN = 2e5 + 5;

ll fac[MAXN+1];

void precomp() {
    fac[0] = 1;
    for(int i=1; i<=MAXN; i++) fac[i] = (i * fac[i-1]) % MOD;
}

void solve() {
    string s;
    cin >> s;

    int minOp = 0;
    char curr = s[0];
    int cnt = 1;

    vector<int> b;

    for(int i=1; i<s.size(); i++) {
        if(s[i] == curr) cnt++;
        else {
            b.push_back(cnt);
            minOp += (cnt - 1);
            cnt = 1;
            curr = s[i];
        }
    }
    b.push_back(cnt);
    minOp += (cnt - 1);

    ll ans = 1;

    for(int &x : b) {
        ans *= x;
        ans %= MOD;
    }

    ans *= fac[s.size() - b.size()];
    ans %= MOD;
    
    cout << minOp << " " << ans << '\n';
}

int main() {
    precomp();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}