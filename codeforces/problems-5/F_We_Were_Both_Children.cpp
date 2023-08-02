#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 2e5 + 20;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v;
    vector<int> occ(n+1, 0);
    vector<int> jumps(n+1, 0);
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        if(x <= n && occ[x] == 0) v.pb(x);
        if(x <= n) occ[x]++;
    }

    vector<int> ans(n+1, 0);
    int cnt = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j * i <= n; j++) {
            ans[j * i] += occ[i];
        }
    }

    for(int i=1; i<=n; i++)
        cnt = max(cnt, ans[i]);
    cout << cnt << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}