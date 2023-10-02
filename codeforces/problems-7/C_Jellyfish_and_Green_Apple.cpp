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

//NE E BINARY SEARCH!!!
void solve() {
    int n, m;
    cin >> n >> m;
    
    if(n == 0) {
        cout << 0 << '\n';
        return ;
    }

    //observacija 1: prvo raspredeluvame celi jabolka
    //observacija 2: n/m = da se predstavime na zbir na
    //reciprocni stepeni na 2
    //go imase vo eden plav numerus
    ll ans = 0;
    int it = 0;

    while(n && it++ <= 5000) {
        n %= m;
        ans += n;
        n *= 2;
    }

    cout << (n ? -1 : ans) << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}