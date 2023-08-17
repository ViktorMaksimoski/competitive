#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)

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

int32_t main() {
    setIO();

    int n;
    cin >> n;

    string s;
    cin >> s;

    set<char> st;
    for(char &ch : s) st.insert(ch);

    int id = 0;
    map<char, int> val;
    for(const char &ch : st) val[ch] = id++;

    map<vector<int>, int> mp;

    ll ans = 0;
    vector<int> v(sz(st), 0);
    for(int i=0; i<sz(s); i++) {
        v[val[s[i]]]++;
        set<int> diff;
        int mn = 1e9;
        
        for(int &x : v) {
            diff.insert(x);
            mn = min(mn, x);
        }
        

        vector<int> newV(sz(st), 0);
        for(int i=0; i<sz(st); i++)
            newV[i] = v[i] - mn;

        if(sz(diff) == 1) ans++;
        ans += mp[newV];
        ans %= mod;
        mp[newV]++;
    }

    cout << ans % mod << '\n';
    return 0;
}