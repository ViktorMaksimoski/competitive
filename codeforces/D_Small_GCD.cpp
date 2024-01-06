#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define int long long

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

vector<vector<int> > divs(maxn+1);
void setup() {
    for(int i=1; i<=maxn; i++)
        for(int j=i; j<=maxn; j+=i)
            divs[j].push_back(i);
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int &x : v) cin >> x;
    sort(all(v));

    vector<int> cnt(maxn+1), occ(maxn+1);
    ll ans = 0;

    for(int i=0; i<n; i++) {
        for(int &x : divs[v[i]]) {
            occ[x] += cnt[x] * (n - 1 - i);
            cnt[x]++;
        }
    }

    for(int i=maxn; i>=1; i--) {
        for(int j=2*i; j<=maxn; j+=i)
            occ[i] -= occ[j];
            ans += occ[i] * i;
    }

    cout << ans << '\n';
}

int32_t main() {
    setup();
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}