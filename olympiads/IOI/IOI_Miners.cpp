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
ll dp[100001][4][4][4][4];
map<char, int> val;
 
ll f(int pos, int f1, int s1, int f2, int s2) {
    if(pos == n) return 0;
    if(dp[pos][f1][s1][f2][s2] != -1) return dp[pos][f1][s1][f2][s2];
 
    ll ans = 0;
 
    int curr = val[s[pos]];
 
    set<int> st1, st2;
    st1.insert(curr);
    st2.insert(curr);
 
    if(f1 != 0) st1.insert(f1);
    if(s1 != 0) st1.insert(s1);
    if(f2 != 0) st2.insert(f2);
    if(s2 != 0) st2.insert(s2);
 
    ans = max(
        st1.size() + f(pos+1, curr, f1, f2, s2),
        st2.size() + f(pos+1, f1, s1, curr, f2)
    );
 
    return dp[pos][f1][s1][f2][s2] = ans;
}
 
int32_t main() {
    setIO();
    memset(dp, -1, sizeof(dp));
 
    val['M'] = 1;
    val['B'] = 2;
    val['F'] = 3;
 
    cin >> n >> s;
    cout << f(0, 0, 0, 0, 0) << '\n';
    return 0;
}