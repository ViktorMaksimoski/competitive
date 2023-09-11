#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;

ll dp[19][11][2][2];
ll f(int pos, int last, bool under, bool started) {
    if(pos == s.size()) return 1;
    if(dp[pos][last][under][started] != -1) return dp[pos][last][under][started];

    ll ans = 0;

    for(int i=0; i<=9; i++) {
        if(i == last && started) continue;
        if(!under && i > (s[pos] - '0')) break;

        bool newUnder = under | (i < (s[pos] - '0'));
        bool newStarted = started | (i > 0);
        int newLast = i;

        ans += f(pos+1, newLast, newUnder, newStarted);
    }

    return dp[pos][last][under][started] = ans;
}

ll cnt(ll bound) {
    s = to_string(bound);

    memset(dp, -1, sizeof(dp));

    return f(0, 10, 0, 0);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll x, y;
    cin >> x >> y;

    cout << cnt(y) - cnt(x-1) << '\n'; 
    return 0;
}