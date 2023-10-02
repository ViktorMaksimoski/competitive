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

    int n, m;
    cin >> n >> m;
    vector<ll> ans(n+1, 0);

    priority_queue<int, vector<int>, greater<int> > row;
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    for(int i=1; i<=n; i++) row.push(i);

    for(int i=0; i<m; i++) {
        int t, w, s;
        cin >> t >> w >> s;
        while(!pq.empty() && pq.top().first <= t) {
            row.push(pq.top().second);
            pq.pop();
        }

        if(row.empty()) continue;
        ans[row.top()] += w;
        pq.push({t+s, row.top()});
        row.pop();
    }

    for(int i=1; i<=n; i++)
        cout << ans[i] << '\n';
    return 0;
}