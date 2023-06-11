#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int LOG = 20;
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

vector<int> v;

vector<ll> meet(int l, int r) {
    vector<ll> ans;

    int len = r - l + 1;
    for(int i=0; i<(1 << len); i++) {
        ll sum = 0;
        for(int j=0; j<len; j++) {
            if(i & (1 << j)) sum += v[l + j];
        }
        ans.push_back(sum);
    }

    return ans;
}

int main() {
    setIO();

    int n, x;
    ll ans = 0;
    cin >> n >> x; 
    v.resize(n);
    for(int &x : v) cin >> x;

    vector<ll> left = meet(0, n/2 - 1);
    vector<ll> right = meet(n/2, n-1);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for(ll i : left) {
        auto from = lower_bound(right.begin(), right.end(), x-i);
        auto to = upper_bound(right.begin(), right.end(), x-i);
        int from_id = from - right.begin();
        int to_id = to - right.begin();
        ans += (to_id - from_id);
    }

    cout << ans << '\n';
    return 0;
}