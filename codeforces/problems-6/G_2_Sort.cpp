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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<bool> good(n);
    good[0] = 1;

    //2^x * v[i] > 2^(x-1) * v[i-1] 
    // => 2 * v[i] > v[i-1]
    for(int i=0; i<n; i++) {
        cin >> v[i];
        if(!i) continue;
        if(2 * v[i] > v[i-1]) good[i] = true;
    }

    int cnt = 0;
    int ans = 0;

    for(int i=0; i<k; i++) {
        cnt += good[i];
    }

    ans += (cnt == k + 1);

    for(int i=1; i<=n-k; i++) {
        cnt -= good[i-1];
        cnt += good[i+k-1];
        ans += (cnt == k);
    }

    // for(bool x : good) cout << x << " ";
    // cout << '\n';
    cout << ans << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}