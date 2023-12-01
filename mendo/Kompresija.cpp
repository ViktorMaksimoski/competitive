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
int dp[51][51];

int f(int pos, int lastM) {
    if(pos >= n) return 0;
    if(dp[pos][lastM] != -1) return dp[pos][lastM];

    //ja pisuvame bukvata
    int ans = f(pos+1, lastM) + 1;

    //stavame M
    if(pos > lastM) ans = min(ans, f(pos, pos) + 1);

    //stavame R
    int len = pos - lastM;
    string a = "";
    string b = "";
    for(int i=lastM; i<pos; i++) a += s[i];
    if(pos+len-1<n)
        for(int i=0; i<len; i++) b += s[pos+i];

    // cout << pos << " " << lastM << '\n';
    // cout << a << " " << b << '\n';

    if(a == b && pos > lastM)
        ans = min(ans, 1 + f(pos+len, lastM));


    return dp[pos][lastM] = ans;
}

int32_t main() {
    setIO();
    memset(dp, -1, sizeof(dp));

    cin >> s;
    n = sz(s);

    cout << f(0, 0) << '\n';
    return 0;
}