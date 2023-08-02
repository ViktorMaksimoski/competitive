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

void solve() {
    int n;
    cin >> n;
    
    ll ans = INT_MIN;
    vector<ll> v(n), even, odd;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        ans = max(ans, 1ll*v[i]);
        if(i % 2 == 1) odd.pb(v[i]);
        else even.pb(v[i]);

    }

    sort(even.rbegin(), even.rend());
    sort(odd.rbegin(), odd.rend());

    ll t = 0;
    for(int i=0; i<sz(odd); i++) {
        t += odd[i];
        ans = max(ans, t);
    }

    t = 0;
    for(int i=0; i<sz(even); i++) {
        t += even[i];
        ans = max(ans, t);
    }

    cout << ans << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}