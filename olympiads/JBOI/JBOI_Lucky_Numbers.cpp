#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
//#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n;
string s;
int dp[251][251][4];
char arr[4] = {'2', '3', '5', '7'};
map<char, int> mp;

bool f(int pos, int seg, char val) {
    //cout << pos << " " << seg << " " << val << '\n';
    if(seg == (val - '0')) return 1;
    if(pos == n) return 0;
    if(dp[pos][seg][mp[val]] != -1) return dp[pos][seg][mp[val]];

    bool ans = 0;

    if(s[pos] != '?') {
        int newSeg = (s[pos] == val ? seg+1 : 1);
        ans |= f(pos+1, newSeg, s[pos]);
    } else {
        for(int i=0; i<4; i++) {
            int newSeg = (arr[i] == val ? seg+1 : 1);
            ans |= f(pos+1, newSeg, arr[i]);
        }
    }

    return dp[pos][seg][mp[val]] = ans;
}

int32_t main() {
    setIO();
    memset(dp, -1, sizeof(dp));

    cin >> n >> s;

    mp[2] = 0;
    mp[3] = 1;
    mp[5] = 2;
    mp[7] = 3;

    cout << (f(0, 0, '1') ? "cool" : "boring") << '\n';
    return 0;
}