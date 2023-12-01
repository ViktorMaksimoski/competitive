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

    ll dist[n+1][n+1];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) cin >> dist[i][j];

    vector<int> v(n);
    for(int &x : v) cin >> x;
    vector<ll> ans(n);
    reverse(all(v));

    vector<bool> vis(n+1);
    for(int i=0; i<n; i++) {
        ll sum = 0;
        vis[v[i]] = 1;

        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][v[i]] + dist[v[i]][k]);
                sum += (vis[j] && vis[k] ? dist[j][k] : 0);
            }
        }
                

        ans[i] = sum;
    }

    reverse(all(ans));
    for(ll &x : ans) cout << x << " ";
    return 0;
}