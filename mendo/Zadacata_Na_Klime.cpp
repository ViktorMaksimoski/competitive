#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool check(string s) {
    if(s[0] == '0') return false;
    ll x = 0;
    for(int i=0; i<sz(s); i++) {
        if(s[i] == '0') continue;
        x += pow(2, sz(s)-i-1);
    }

    ll curr = 1;
    while(curr <= x) {
        if(curr == x) return true;
        curr *= 5;
    }

    return false;
}

int32_t main() {
    setIO();

    string s;
    cin >> s;
    vector<int> dp(sz(s)+1, 1e9);
    dp[0] = 0;

    for(int i=1; i<=sz(s); i++) {
        string st = "";
        for(int j=i; j>=1; j--) {
            st += s[j-1];
            string newStr = st;
            reverse(all(newStr));
            bool b = check(newStr);
            if(b) {
                dp[i] = min(dp[i], dp[j-1] + 1);
            }
        }
    }

    cout << (dp[sz(s)] == 1e9 ? -1 : dp[sz(s)]) << '\n';
    return 0;
}