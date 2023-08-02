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
    int ans = 1e9;
    cin >> n;
    vector<int> v(2*n);

    for(int &x : v) cin >> x;
    sort(v.begin(), v.end());

    for(int i=0; i<2*n-1; i++) {
        for(int j=i+1; j<2*n; j++) {
            map<int, int> occ;
            for(int k=0; k<2*n; k++)
                if(k != i && k != j)
                    occ[v[k]]++;

            int res = 0;
            vector<int> work;
            for(auto &x : occ) {
                if(x.second & 1) work.push_back(x.first);
            }

            int l=0, r=work.size()-1;
            while(l < r) {
                res += abs(work[r] - work[l]);
                l++, r--;
            }  

            int res2 = 0;
            for(int k=1; k<work.size(); k+=2) {
                res2 += (work[k] - work[k-1]);
            }          

            // cout << "[ ";
            // for(int &x : work)
            //     cout << x << " ";
            // cout << "] - " << min(res, res2) << '\n';
            ans = min({ ans, res, res2 });
        }
    }

    cout << ans << '\n';
    return 0;
}