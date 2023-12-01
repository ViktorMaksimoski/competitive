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

void solve() {
    int n, m, d;
    cin >> n >> m >> d;

    ll total = 0, ans = 0;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        if(x <= 0) continue;

        if(pq.size() < m) {
            total += x;
            pq.push(x);
        } else if(pq.size() == m && pq.top() < x) {
            total -= pq.top();
            pq.pop();
            total += x;
            pq.push(x);
        }

        ans = max(ans, total - d * (i + 1));
    }

    cout << ans << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}