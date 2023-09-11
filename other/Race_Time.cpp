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

struct Car { int s, d; };

int32_t main() {
    setIO();

    int n, k;
    cin >> n >> k;

    vector<Car> v(n);
    for(Car &c : v) cin >> c.s >> c.d;

    auto f = [&](double x) {
        double mn=1e18, mx=-1e18;

        for(Car &c : v) {
            double res = c.s * x + c.d;
            mx = max(mx, res);
            mn = min(mn, res);
        }

        return mx - mn;
    };

    double l=0.0, r=double(k);
    while(r - l >= eps) {
        double mid1 = l + (r - l) / 3.0;
        double mid2 = r - (r - l) / 3.0;

        if(f(mid1) > f(mid2)) l = mid1;
        else r = mid2;
    }

    cout << setprecision(6) << fixed << f(l) << '\n';
    return 0;
}