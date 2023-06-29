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

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int ans = n * a;
    int useM = n / m;
    int ans2 = useM * b + (n - useM * m) * a;
    int ans3 = 0;
    if(n % m > 0) ans3 = (n/m+1) * b;
    else ans3 = (n / m) * b;

    cout << min({ ans, ans2, ans3 }) << '\n';
    return 0;
}