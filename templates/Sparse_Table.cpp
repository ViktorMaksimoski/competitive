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

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    vector<vector<int> > table(n+1, vector<int>(20, 0));
    for(int i=0; i<n; i++) cin >> v[i], table[i][0] = v[i]; 

    //build table
    for(int k=1; k<20; k++)
        for(int i=0; i+(1<<k)-1<n; i++)
            table[i][k] = min(table[i][k-1], table[i+(1<<(k-1))][k-1]);

    function<int(int, int)> query = [&](int a, int b) {
        int len = b-a+1;
        int k=0;
        while((1 << (k+1)) <= len) k++;

        return min(
            table[a][k],
            table[b-(1<<k)+1][k]
        );
    };

    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b-1) << '\n';
    }

    return 0;
}