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

    int k, n;
    cin >> k >> n;

    vector<vector<int> > price(k, vector<int>(n));
    for(int i=0; i<k; i++)
        for(int j=0; j<n; j++) cin >> price[i][j];

    int total[1 << k][n];
    memset(total, 100, sizeof(total));


    //by day 1 we can buy only one product
    for(int i=0; i<k; i++)
        total[1 << i][0] = price[i][0];

    //either we don't buy anything on day D
    //or we buy a element that is in the subset
    for(int d = 1; d < n; d++) {
    for(int s = 0; s < (1<<k); s++) {
        total[s][d] = total[s][d-1];
        for(int x = 0; x < k; x++) {
            if(s&(1<<x)) {
                total[s][d] = min(total[s][d], total[s^(1<<x)][d-1]+price[x][d]);
            }
        }
    }
}

    cout << total[(1<<k)-1][n-1] << '\n';
    return 0;
}