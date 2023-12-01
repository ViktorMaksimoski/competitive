#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Audience {
    int strength;
    int id;

    bool operator<(Audience &b) {
        if(strength == b.strength)
            return (id < b.id);
        return (strength > b.strength);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, p, k;
    cin >> n >> p >> k;

    vector<Audience> v(n);
    for(int i=0; i<n; i++) cin >> v[i].strength, v[i].id = i;
    sort(all(v));

    int pos[n][p];
    for(int i=0; i<n; i++)
        for(int j=0; j<p; j++) cin >> pos[i][j];

    vector<vector<ll> > dp(n+1, vector<ll>(1 << p, -1));
    dp[0][0] = 0;
    for(int i=1; i<=n; i++) {
        for(int s=0; s<(1<<p); s++) {
            int set = __builtin_popcount(s);
            int x = i - set - 1;

            if(dp[i-1][s] >= 0) 
                dp[i][s] = dp[i-1][s] + (x < k ? v[i-1].strength : 0);

            for(int j=0; j<p; j++)
                if((s & (1 << j)) && dp[i-1][s^(1<<j)] != -1)
                    dp[i][s] = max(dp[i][s], pos[v[i-1].id][j] + dp[i-1][s^(1<<j)]);
        }
    }

    cout << dp[n][(1 << p) - 1] << '\n';
    return 0;
}