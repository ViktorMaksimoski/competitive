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

int x=2001;
int main() {
       setIO();

       x++;
       cout << x;

       return 0;
}