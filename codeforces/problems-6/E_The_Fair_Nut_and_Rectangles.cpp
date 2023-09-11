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
 
struct Rect {
    int x, y;
    ll a;
    bool operator<(Rect &b) {
        return x < b.x;
    }
};
 
int32_t main() {
    setIO();
 
    int n;
    cin >> n;
 
    vector<Rect> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i].x >> v[i].y >> v[i].a;
    sort(v.begin() + 1, v.end());
 
    vector<ll> dp(n+1, 0);
 
    auto slope = [&](int i, int j) {
        return (double)(dp[i] - dp[j]) / (v[i].x - v[j].x);
    };
 
    deque<ll> q;
    q.push_back(0);
    v[0].x = 0, v[0].y = 0, v[0].a = 0;
 
    for(int i=1; i<=n; i++) {
        while(q.size() > 1 && slope(q[0], q[1]) >= v[i].y) q.pop_front();
 
        int j = q.front();
        dp[i] = max(
            dp[i-1],
            1ll * v[i].x * v[i].y - v[i].a + dp[j] - 1ll * v[j].x * v[i].y
        );
 
        while(q.size() > 1 && slope(q[q.size()-2], q.back()) <= slope(q.back(), i))
            q.pop_back();
        q.push_back(i);
    }
 
    cout << dp[n] << '\n';
    return 0;
}
