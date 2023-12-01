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
    int n, m;
    cin >> n >> m;
    vector<int> deg(n+1);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        deg[a]++, deg[b]++;
    }

    vector<int> cnt(n+1);
    for(int i=1; i<=n; i++) cnt[deg[i]]++;

    set<pii> s;
    for(int i=2; i<=n; i++)
        if(cnt[i]) s.insert({ cnt[i], i });

    if(sz(s) == 1) {
        pii x = *s.begin();
        cout << x.second << " " << x.second - 1 << '\n';
    } else {
        pii x = *s.begin();
        pii y = *(--s.end());
        cout << x.second << " " << y.second - 1 << '\n';
    }
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}