#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

const int MOD = 1234567;

ll n;
int k;
string s = "";
int currPos = 0;

ll dp[51][51][2][2];

ll f(int pos, int cnt, bool under, bool good) {
    if(cnt > k) return 0;
    if(cnt == k) return (good);
    if(pos == s.size()) return (cnt == k && good);
    if(dp[pos][cnt][under][good] != -1) return dp[pos][cnt][under][good];
    
    ll ans = 0;

    for(int i=0; i<=1; i++) {
        int x = s[pos] - '0';
        if(i > x && !under) continue;
        int newCnt = cnt + i;
        int newGood = good | (pos == currPos && i == 1);
        ans += f(pos+1, newCnt, under | (i < x), newGood);
        ans %= MOD;
    }

    return dp[pos][cnt][under][good] = ans % MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    ll m = n;
    while(m) {
        if(m % 2 == 1) s += '1';
        else s += '0';
        m /= 2;
    }
    
    ll ans = 0;
    ll ans2 = 0;
    if(__builtin_popcount(n) == k) ans2 = n;
    reverse(all(s));

    for(int i=0; i<sz(s); i++) {
        memset(dp, -1, sizeof(dp));

        currPos = i;
        ll a = f(0, 0, 0, 0);
        ll b = (1ll << (sz(s) - i - 1)) % MOD;
        ans += (a * b) % MOD;
        ans %= MOD;
        //cout << i << ": " << a << '\n';
        //cout << a * b << '\n';
    }
    //cout << s << '\n';
    
    cout << (ans - ans2) % MOD << '\n';
    return 0;
}