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

    int n, d, p;
    cin >> n >> d >> p;

    vector<int> f(n);
    for(int &x : f) cin >> x;
    sort(rall(f));

    vector<ll> prefix(n);
    vector<ll> blocks;
    ll curr = 0;
    for(int i=0; i<n; i++) {
        prefix[i] = f[i];
        if(i) prefix[i] += prefix[i-1];
        curr += f[i];
        if((i + 1) % d == 0) {
            blocks.push_back(curr);
            curr = 0;
        }
    }
    blocks.push_back(curr);

    int pos = -1;
    int l=0, r=blocks.size()-1;

    while(l <= r) {
        int mid = (l + r) / 2;

        if(blocks[mid] >= p) {
            pos = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    // for(int &x : f) cout << x << " ";
    // cout << '\n';
    // for(ll &x : blocks) cout << x << " ";
    // cout << '\n';
    // cout << pos << '\n';

    if(pos == -1) {
        cout << prefix.back() << '\n';
        return 0;
    }

    ll ans = prefix.back();
    int np = min(n-1, (pos+1)*d-1);
    ans -= prefix[np];
    ans += (1ll * (pos + 1) * p);

    cout << ans << '\n';
    return 0;
}