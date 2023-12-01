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

vector<ll> fib(51);
ll n, x, y;

bool f(ll x1, ll y1, ll x2, ll y2) {
    //cout << "(" << x1 << ", " << y1 << ") (" << x2 << ", " << y2 << ")\n";
    if(x1 > x2 || y1 > y2) return 0;
    if(x1 > x || x2 < x || y1 > y || y2 < y) return 0;
    if(x1 == x2 && y1 == y2) return (x1 == x && y1 == y);

    bool ans = 0;

    if(x2 - x1 <= y2 - y1) {
        ans |= f(x1, y1+(x2-x1+1), x2, y2);
        ans |= f(x1, y1, x2, y2-(x2-x1+1));
    } else {
        ans |= f(x1+(y2-y1+1), y1, x2, y2);
        ans |= f(x1, y1, x2-(y2-y1+1), y2);
    }

    return ans;
}

int32_t main() {
    setIO();

    fib[0] = fib[1] = 1;
    for(int i=2; i<50; i++) fib[i] = fib[i-1] + fib[i-2];

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> x >> y;
        cout << (f(1, 1, fib[n], fib[n+1]) ? "YES" : "NO") << '\n';
    }

    return 0;
}