#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    vector<vector<int> > st(n), et(n);
    vector<pii> intervals;

    for(int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        intervals.pb({ a-1, b-1 });
        st[a-1].push_back(i);
        et[b-1].push_back(i);
    }

    vector<int> left(n, 0);
    multiset<int> ms;

    for(int i=0; i<n; i++) {
        for(int &x : st[i]) {
            ms.insert(intervals[x].first-1);
        }
        if(!ms.size()) left[i] = i-1;
        else left[i] = *ms.begin();
    
        for(int &x : et[i]) {
            ms.erase(ms.find(intervals[x].first-1));
        }
    }

    vector<ll> dp(n, 0);
    dp[0] = v[0];
    for(int i=1; i<n; i++) {
        if(left[i] == -1) {
            dp[i] = max(1ll * v[i], dp[i-1]);
        } else {
            dp[i] = max(dp[i-1], v[i] + dp[left[i]]);
        }
    }

    cout << dp[n-1] << '\n';
    return 0;
}