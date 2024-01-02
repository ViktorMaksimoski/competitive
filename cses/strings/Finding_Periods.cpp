#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int p = 31;
const int mod = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    
    int n = s.size();

    vector<ll> pw(n+1), hash(n);
    pw[0] = 1, hash[0] = s[0] - 'a' + 1;
    for(int i=1; i<=n; i++)
        pw[i] = (pw[i-1] * p) % mod;
    for(int i=1; i<n; i++)
        hash[i] = (hash[i-1] + (s[i] - 'a' + 1) * pw[i]) % mod;

    auto getHash = [&](int l, int r) {
        ll ans = hash[r] - (l ? hash[l-1] : 0);
        return (ans + mod) % mod;
    };

    for(int i=0; i<n; i++) {
        bool ok = 1;

        for(int j=0; j<n; j+=(i+1)) {
            int k = j + i;
            if(k < n && getHash(j, k) != (getHash(0, i) * pw[j]) % mod) ok = 0;
            else if(k >= n && getHash(j, n-1) != (getHash(0, n-j-1) * pw[j]) % mod) ok = 0;
        }

        if(ok) cout << i + 1 << " ";
    }

    return 0;
}