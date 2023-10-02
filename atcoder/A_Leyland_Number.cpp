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

ll exp(int a, int b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a;
        a = a * a;
        b /= 2;
    } 
    return ans;
}

int32_t main() {
    setIO();

    int a, b;
    cin >> a >> b;
    cout << exp(a, b) + exp(b, a) << '\n';
    return 0;
}