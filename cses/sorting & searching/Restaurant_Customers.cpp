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

    int n, ans = 0;
    cin >> n;

    set<int> s;
    vector<pii> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
        s.insert(v[i].first);
        s.insert(v[i].second);
    }

    vector<int> comp(all(s));
    vector<int> line(sz(comp)+5, 0);

    for(pii &x : v) {
        x.first = lower_bound(all(comp), x.first) - comp.begin();
        x.second = lower_bound(all(comp), x.second) - comp.begin();
        line[x.first]++;
        line[x.second+1]--;
    }

    int cnt = 0;
    for(int i=0; i<line.size(); i++) {
        cnt += line[i];
        ans = max(ans, cnt);
    }

    cout << ans << '\n';
    return 0;
}