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

int main() {
    setIO();

    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(ll &x : v) cin >> x;
    ll ans = 0;

    map<ll, int> cnt;
    int i=0, j=0, diff=0;
    while(i < n) {
        while(j < n && diff + (cnt[v[j]] == 0) <= k) {
            cnt[v[j]]++;
            diff += (cnt[v[j]] == 1);
            j++;

        }

        ans += (j - i);
        diff -= (cnt[v[i]] == 1);
        cnt[v[i]]--, i++;
    }
    
    cout << ans << '\n';
    return 0;
}