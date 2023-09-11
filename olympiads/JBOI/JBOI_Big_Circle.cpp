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
using pff = pair<double, double>;
 
const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;
 
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

double getDist(pff a, pff b) {
    double x = (a.first - b.first) * (a.first - b.first);
    double y = (a.second - b.second) * (a.second - b.second);
    return x + y;
}
 
int32_t main() {
    setIO();
 
    int n;
    cin >> n;
 
    vector<pff> v(n);
    for(pff &x : v)
        cin >> x.first >> x.second;
 
    sort(all(v));
 
    double ans = 1e18;

    if(n > 97000) {
        ans = min(ans, getDist(v[0], v.back()));
        for(int i=0; i<n; i++)
            ans = min(ans, getDist(v[i], v[i+1]));
        cout << setprecision(2) << fixed << sqrt(ans) << '\n';
        return 0;
    }
 
    set<pff> s;
    s.insert(v[0]);
 
    for(int i=1; i<n; i++) {
        auto l = s.lower_bound({ v[i].first - ans, v[i].second - ans });
        auto r = s.upper_bound({ v[i].first, v[i].second + ans });
        if(l == s.end()) continue;
 
        for(auto p=l; p!=r; p++) {
            pff curr = *p;
 
            double dist = (v[i].first - curr.first) * (v[i].first - curr.first);
            dist += (v[i].second - curr.second) * (v[i].second - curr.second);
 
            ans = min(dist, ans);
        }
 
        s.insert(v[i]);
    }
 
    cout << setprecision(2) << fixed << sqrt(ans) << '\n';
    return 0;
}