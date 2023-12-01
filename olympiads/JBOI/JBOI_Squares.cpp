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
 
int32_t main() {
    setIO();
 
    int n;
    cin >> n;
    ll ans = 0;
 
    for(int i=1; i*i<=n; i++) {
        if(n % i > 0) continue;
        for(int d=1; d<=(i+1)/2; d++) ans += (__gcd(d, i+1) == 1);
        if(n / i != i)
            for(int d=1; d<=(n/i+1)/2; d++) ans += (__gcd(d, n/i+1) == 1);
    }
 
    cout << ans << '\n';
    return 0;
}