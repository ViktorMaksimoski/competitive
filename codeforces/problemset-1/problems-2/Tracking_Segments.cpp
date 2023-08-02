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

int n;
bool check(int mid, vector<pair<int, int> >& seg, vector<int>& q) {
    vector<int> v(n, 0);
    for(int i=0; i<mid; i++) v[q[i]-1] = 1;
    vector<int> pref(n+1, 0);
    for(int i=0; i<n; i++)
        pref[i+1] = pref[i] + v[i];

    for(auto &s : seg) {
        int l=s.first-1, r=s.second-1;
        if(2*(pref[r+1] - pref[l]) > (r - l + 1))
            return true;
    }

    return false;
}

void solve() {
    int m;
    cin >> n >> m;
    vector<pair<int, int> > segments(m);
    for(auto &x : segments) cin >> x.first >> x.second;
    int q;
    cin >> q;
    vector<int> queries(q);
    for(int &x : queries) cin >> x;

    int l=1, r=q, ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid, segments, queries)) {
            ans = mid;
            r = mid-1;
        } else l = mid+1;
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