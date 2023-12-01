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
    int n, k;
    cin >> n >> k;

    vector<bool> vis(n+1, 0);
    vector<int> v(n);
    for(int &x : v) cin >> x, vis[x] = 1;

    vector<int> arr(n+1, 0);
    for(int i=1; i<=n; i++) arr[i] = v[i-1];

    k %= (n + 1);

    int mex = 0;
    for(int i=0; i<n+1; i++) {
        if(!vis[i]) {
            mex = i;
            break;
        }
    }

    arr[0] = mex;
    
    int pos = 1;
    if(k >= 2) {
        pos = n;
        k -= 2;
        pos -= k;
    } else {
        pos -= k;
    }

    for(int i=pos; i<pos+n; i++)
        cout << arr[i%(n+1)] << " ";
    cout << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}