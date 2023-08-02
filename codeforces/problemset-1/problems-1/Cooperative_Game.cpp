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

void print(const vector<int> &v) {
    cout << "next";
    for(const int &x : v) cout << " " << x;
    cout << '\n';
    fflush(stdout);
}

int n;
vector<int> v(20);
char s[20];

void read() {
    cin >> n;
    for(int i=0; i<n; i++) {
        scanf(" %s", s);
        for(int j=0; s[j]; j++) v[s[j]-'0'] = i;
    }
}

int main() {

    for(;;) {
        print({0, 1});
        read();
        print({ 0 });
        read();
        if(v[0] == v[1]) break;
    }

    for(;;) {
        print({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });
        read();
        if(v[0] == v[2]) break;
    }
    cout << "done\n";
    return 0;
}