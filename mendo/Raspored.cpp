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

int main() {
    setIO();

    int n;
    set<int> s;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
        s.insert(v[i]);
    }

    if(s.size() == 1) {
        if(n == 1) cout << 1 << '\n';
        else cout << n - 1 << '\n';
        return 0;
    }

    if(s.size() == 2) {
        int ans = 0, last = 0;
        for(int i=1; i<n; i++) {
            if(v[i] == v[last]) {
                ans++;
            } else {
                last = i;
            }
        }

        cout << ans << '\n';
        return 0;
    }

    int ans = 1e9;
    for(int i=1; i<=3; i++) {
        vector<int> v2;
        int ans1 = 0, last = 0;
        for(int &x : v)
            if(x != i) v2.push_back(x);

        ans1 += (v.size() - v2.size());
        for(int i=1; i<v2.size(); i++) {
            if(v2[i] == v2[last]) {
                ans1++;
            } else {
                last = i;
            }
        }
        ans = min(ans, ans1);
    }

    cout << ans << '\n';
    return 0;
}