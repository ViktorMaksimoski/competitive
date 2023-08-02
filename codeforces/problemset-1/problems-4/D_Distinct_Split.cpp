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

int32_t main() {
    setIO();

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        str s;
        cin >> s;

        int ans = 0;
        int diff1=0, diff2=0;
        map<char, int> occ1, occ2;
        for(char &ch : s) {
            occ2[ch]++;
            if(occ2[ch] == 1) diff2++;
        }
        ans = diff2;

        for(char &ch : s) {
            occ2[ch]--;
            if(occ2[ch] == 0) diff2--;
            occ1[ch]++;
            if(occ1[ch] == 1) diff1++;
            ans = max(ans, diff1 + diff2);
        }

        cout << ans << '\n';
    }

    return 0;
}