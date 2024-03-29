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

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    ll ans = v.back() - v[0] + 1;
    priority_queue<int> pq;

    for(int i=1; i<n; i++) pq.push(v[i] - v[i-1] - 1);
    for(int i=0; i<k-1; i++) ans -= pq.top(), pq.pop();

    cout << ans << '\n';
    return 0;
}