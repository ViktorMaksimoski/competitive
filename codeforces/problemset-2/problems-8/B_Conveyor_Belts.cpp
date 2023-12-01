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

void solve() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    int my_belt;
    int other_belt;

    if(x1 <= n/2) my_belt = x1;
    else my_belt = n - x1 + 1;
    if(y1 <= n/2) my_belt = min(my_belt, y1);
    else my_belt = min(my_belt, n - y1 + 1);

    if(x2 <= n/2) other_belt = x2;
    else other_belt = n - x2 + 1;
    if(y2 <= n/2) other_belt = min(other_belt, y2);
    else other_belt = min(other_belt, n - y2 + 1);

    cout << abs(my_belt - other_belt) << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}