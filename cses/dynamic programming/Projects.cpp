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
const int maxn = 4e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct Event { int from, to, val; };
vector<vector<pii> > v;
int n;
ll dp[maxn];

ll f(int pos) {
    if(pos >= 2*n) return 0;
    if(dp[pos] != -1) return dp[pos];

    ll ans = f(pos+1);
    for(pii &x : v[pos])
        ans = max(ans, x.second + f(x.first+1));

    return dp[pos] = ans;
}

int32_t main() {
    memset(dp, -1, sizeof(dp));
    setIO();

    cin >> n;

    set<int> comp2;
    vector<Event> events(n);
    v.resize(2*n);

    for(int i=0; i<n; i++) {
        cin >> events[i].from >> events[i].to >> events[i].val;
        comp2.insert(events[i].from);
        comp2.insert(events[i].to);
    }

    vector<int> comp(all(comp2));
    for(int i=0; i<n; i++) {
        events[i].from = lower_bound(all(comp), events[i].from) - comp.begin();
        events[i].to = lower_bound(all(comp), events[i].to) - comp.begin();
        v[events[i].from].push_back({ events[i].to, events[i].val });
    }

    cout << f(0) << '\n';
    return 0;
}