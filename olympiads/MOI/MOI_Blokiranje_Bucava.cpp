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

    int n, r, d;
    cin >> n >> r >> d;

    ll ans = 0;

    priority_queue<pii, vector<pii>, greater<pii> > pq;

    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        pq.push({ a, b });
    }

    while(!pq.empty()) {
        vector<pii> v;
        v.push_back(pq.top());
        pq.pop();

        while(!pq.empty() && pq.top().first - v[0].first <= 2*r) {
            v.push_back(pq.top());
            pq.pop();
        }

        int moves = (v[0].second + d - 1) / d;
        ans += (v[0].second + d - 1) / d;

        for(pii &x : v) {
            if(x.second > moves * d) {
                x.second -= moves * d;
                pq.push(x);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}