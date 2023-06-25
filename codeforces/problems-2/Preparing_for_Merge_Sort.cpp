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
    vector<vector<int> > ans;
    
    while(n--) {
        //we process the numers in the array as they come in the input.
        //for each number, we want to find tyhe first subsequence such that
        //it's largest element is smaller than the current elemnt
        //if there isn't such sequence, we start a new one :)
        int x; cin >> x;
        int l=0, r = ans.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(ans[mid].back() < x) r = mid;
            else l = mid + 1;
        }
        if(l == ans.size()) ans.push_back({ x });
        else ans[l].push_back(x);
    }

    for(auto &vx : ans) {
        for(auto &x : vx) cout << x << " ";
        cout << '\n';
    }

    return 0;
}