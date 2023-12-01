#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct T {
    int cores, rate, price;

    bool operator<(T &t) {
        if(rate == t.rate) return price < t.price;
        return rate > t.rate;
    }
};

int main() {
    int n;
    cin >> n;

    vector<T> v;
    v.push_back(T{0, 0, 0});
    ll total = 0;
    for(int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        total += a;
        v.push_back(T{a, b, -c});
    }

    int m;
    cin >> m;

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(T{-a, b, c});
    }

    sort(v.begin()+1, v.end());

    vector<vector<ll> > dp(2, vector<ll>(total+1, -1e18));
    dp[0][0] = 0;
    for(int i=1; i<=n+m; i++) {
        for(int j=0; j<=total; j++) {
            dp[1][j] = dp[0][j];
            if(j - v[i].cores >= 0 && j - v[i].cores <= total && dp[0][j-v[i].cores] != -1e18)
                dp[1][j] = max(dp[0][j], dp[0][j-v[i].cores] + v[i].price);
        }
        swap(dp[0], dp[1]);
    }

    ll ans = -1e18;
    for(int i=0; i<=total; i++) ans = max(ans, dp[0][i]);
    cout << ans << '\n';
    return 0;
}