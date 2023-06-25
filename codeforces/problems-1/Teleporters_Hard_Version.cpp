#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    if(name != "") setUSA(name);
}

void solve() {
    ll n, c, ans = 0;
    cin >> n >> c;

    vector<pair<ll, ll> > v(n);
    vector<ll> prefix(n+1, 0);
    for(int i=0; i<n; i++) {
        ll x;
        cin >> x;
        v[i] = { min(x+i+1,x+n-i), x+i+1 };
    }

    sort(v.begin(), v.end());
    for(int i=0; i<n; i++)
        prefix[i+1] = prefix[i] + v[i].first;

    for(int i=0; i<n; i++) {
        ll left = c - v[i].second;
        int l=0, r=n;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            ll cost = prefix[mid];
            ll tp = mid + 1;

            if(mid > i)
                tp--, cost -= v[i].first;

            if(cost <= left) {
                ans = max(ans, tp);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve(); 

    return 0;
}