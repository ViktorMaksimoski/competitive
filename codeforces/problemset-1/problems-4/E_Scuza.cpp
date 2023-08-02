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
#include <functional>
#include <climits>

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
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    vector<ll> prefix(n+1, 0);
    vector<int> mx(n+1, 0);
    for(int i=0; i<n; i++) {
        cin >> v[i];
        prefix[i+1] = prefix[i] + v[i];
        mx[i+1] = max(mx[i], v[i]);
    }

    while(q--) {
        int x;
        cin >> x;
        
        int l=1, r=n;
        int pos=0;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(mx[mid] <= x) {
                pos = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        cout << prefix[pos] << " ";
    }
    cout << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}