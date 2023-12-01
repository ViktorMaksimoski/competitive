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

int n, m;
vector<pii> v;
vector<int> comp;
set<int> s;

int f(int p) {
    vector<int> line(sz(comp)+2, 0);
    int ans = 0;

    for(pii &x : v) {
        if(x.first == p || x.second == p) continue;
        int a = lower_bound(all(comp), x.first) - comp.begin();
        int b = lower_bound(all(comp), x.second) - comp.begin();
        line[a]++;
        line[b+1]--;
    }

    int curr = 0;
    for(int i=0; i<sz(line); i++) {
        curr += line[i];
        ans = max(ans, curr);
    }

    return ans;
}

void solve() {
    cin >> n >> m;
    v.clear();
    v.resize(n);
    s.clear();
    comp.clear();
    for(pii &x : v) {
        cin >> x.first >> x.second;
        s.insert(x.first);
        s.insert(x.second);
    }

    comp = vector<int>(all(s));

    cout << max(f(1), f(m)) << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}