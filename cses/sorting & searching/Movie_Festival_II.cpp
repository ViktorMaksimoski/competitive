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

    int n, k;
    int ans = 0;
    cin >> n >> k;
    vector<pair<int, int> > v(n);
    for(auto &x : v)
        cin >> x.first >> x.second;

    sort(v.begin(), v.end(), cmp);
    multiset<int> ms;
    for(int i=0; i<k; i++)
        ms.insert(0);

    for(int i=0; i<n; i++) {
        auto it = ms.upper_bound(v[i].first);
        if(it == ms.begin()) continue;

        ms.erase(--it);
        ms.insert(v[i].second);
        ans++;
    }

    cout << ans << '\n';
    return 0;
}