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

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second)
        return (a.first < b.first);
    return (a.second < b.second);
}

int main() {
    setIO();

    int n, ans = 0;
    cin >> n;
    vector<pair<int, int> > v(n);
    for(auto &x : v)
        cin >> x.first >> x.second;

    sort(v.begin(), v.end(), cmp);

    int last = -1;
    for(int i=0; i<n; i++) {
        if(v[i].first >= last) {
            ans++;
            last = v[i].second;
        }
    }

    cout << ans << '\n';
    return 0;
}