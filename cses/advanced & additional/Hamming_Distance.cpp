#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <stack>
#include <cstring>
#include <chrono>
#include <random>
#include <numeric>
#include <bitset>
#include <array>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << ": " << x << '\n'
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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

ll toNum(str s) {
    int siz = sz(s);
    ll ans = 0;

    int id = 0;
    for(int i=siz-1; i>=0; i--) {
        if(s[id++] == '0') continue;
        ans += 1ll * pow(2, i);
    }

    return ans;
}

int32_t main() {
    setIO();

    int n, k;
    int ans = 50;
    cin >> n >> k;

    vector<ll> v;
    //cout << "100: " << toNum("100") << '\n';
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        v.pb(toNum(s));
    }

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            ans = min(ans, __builtin_popcount(v[i] ^ v[j]));
        }
    }


    cout << ans << '\n';
    return 0;
}