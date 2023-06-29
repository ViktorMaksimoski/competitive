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

    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    vector<pair<int, int> > ans;

    for(int i=0; i<n; i++) {
        int last = -1, s = v[i];
        for(int j=i+1; j<n; j++) {
            if(v[j] < s) {
                s = v[j];
                last = j;
            }
        }

        if(last != -1) ans.push_back({ i, last }), swap(v[i], v[last]);
    }

    cout << ans.size() << '\n';
    for(auto &x : ans)
        cout << x.first << " " << x.second << '\n';
    return 0;
}