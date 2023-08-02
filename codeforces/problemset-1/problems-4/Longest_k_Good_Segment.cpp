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

int32_t main() {
    setIO();

    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    for(int &x : v) cin >> x;

    int ans_l = -1, ans_r = -2;
    int l=0, r=0, diff=0;
    map<int, int> occ;
    while(r < n) {
        occ[v[r]]++;
        if(occ[v[r]] == 1) diff++;

        while(diff > k) {
            occ[v[l]]--;
            if(occ[v[l]] == 0) diff--;
            l++;
        }

        if(r - l > ans_r - ans_l) {
            ans_r = r;
            ans_l = l;
        }
        r++;
    }

    cout << ans_l + 1 << " " << ans_r + 1 << '\n';
    return 0;
}