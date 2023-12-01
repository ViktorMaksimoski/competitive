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
    int n;
    cin >> n;
    vector<vector<ll>> prefix(n+1, vector<ll>(2));
    vector<int> v(n);

    for(int &x : v) cin >> x;

    ll ans[2] = {0, 0};
    string s;
    cin >> s;

    for(int i=0; i<n; i++) {
        prefix[i+1][0] = prefix[i][0];
        prefix[i+1][1] = prefix[i][1];
        if(s[i] == '1') ans[1] ^= v[i], prefix[i+1][1] ^= v[i];
        else ans[0] ^= v[i], prefix[i+1][0] ^= v[i];
    }

    int q;
    cin >> q;

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int a, b;
            cin >> a >> b;

            ans[1] ^= (prefix[b][1] ^ prefix[a-1][1]);
            ans[1] ^= (prefix[b][0] ^ prefix[a-1][0]);

            ans[0] ^= (prefix[b][0] ^ prefix[a-1][0]);
            ans[0] ^= (prefix[b][1] ^ prefix[a-1][1]);
        } else {
            int a;
            cin >> a;
            cout << ans[a] << " ";
        }
    }

    cout << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}