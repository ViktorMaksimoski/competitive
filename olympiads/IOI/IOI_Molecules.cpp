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

vector<int> find_subset(int l, int u, vector<int> w) {

    vector<pii> v;
    for(int i=0; i<sz(w); i++) {
        v.push_back({ w[i], i });
    }

    sort(all(v));

    int i=0, j=0;
    ll total = 0;

    while(j < sz(v) && i < sz(v)) {
        total += v[j].first;

        while(i < sz(v) && total > u) {
            total -= v[i].first;
            i++;
        }

        if(l <= total && total <= u) {
            vector<int> ans;
            for(int it=i; it<=j; it++) {
                ans.push_back(v[it].second);
            }
            sort(all(ans));
            return ans;
        }

        j++;
    }

    return vector<int>{};
}

// int32_t main() {
//     setIO();

//     int l, u;
//     cin >> l >> u;
//     int n;
//     cin >> n;
//     vector<int> v(n);

//     for(int &x : v) cin >> x;

//     vector<int> ans = find_subset(l, u, v);

//     for(int &x : ans) cout << x << " ";

//     return 0;
// }