#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    vector<bool> dp(k+1, 0);
    for(int i=1; i<=k; i++)
        for(int &x : v)
            if(i >= x) dp[i] = (!dp[i-x] ? 1 : dp[i]);
    cout << (dp[k] ? "First" : "Second") << '\n';
    return 0;
}