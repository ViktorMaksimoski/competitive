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

    string s;
    cin >> s;

    for(int i=0; i<s.size(); i++) {
        int dig = s[i] - '0';
        if(i == 0 && s[i] == '9') continue;
        if(9-dig < dig) {
            s[i] = char('0' + (9 - dig));
        }
    } 

    cout << s << '\n';
    return 0;
}