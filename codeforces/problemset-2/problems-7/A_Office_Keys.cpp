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

int n, k, pos;
vector<int> a, b;

bool check(ll t) {
    vector<bool> vis(k, 0);
    int cnt = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) {
            if(vis[j]) continue;
            ll time = abs(a[i] - b[j]) + abs(b[j] - pos);
            
            if(time <= t) {
                cnt++;
                vis[j] = true;
                break;
            }
        }
    }

    return (cnt == n);
}

int32_t main() {
    setIO();

    cin >> n >> k >> pos;
    a.resize(n);
    b.resize(k);
 
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    sort(all(a)); sort(all(b));

    ll ans = 0;
    ll l=0, r=1e15;
    
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        if(check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}