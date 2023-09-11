#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1<<20];
int mat[20];

int f(int mask) {
    if(mask == (1<<n) - 1) return 0;
    if(dp[mask] != -1) return dp[mask];

    int ans = 1e9;

    for(int i=0; i<n; i++) {
        if(mask & (1 << i)) continue;
        int newMask = mask | (1 << i);
        int cost = __builtin_popcount(mat[i] & mask);

        ans = min(ans, cost + f(newMask));
    }

    return dp[mask] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    memset(dp, -1, sizeof(dp));

    for(int i=0; i<n; i++) {
        int res = 0;
        for(int j=0; j<n; j++) {
            char ch;
            cin >> ch;
            if(ch == 'D') res |= (1 << j);
        }
        mat[i] = res;
    }

    cout << f(0) << '\n';
    return 0;
}