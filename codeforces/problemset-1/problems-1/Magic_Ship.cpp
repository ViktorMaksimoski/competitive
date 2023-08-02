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

pair<int, int> a, b;
int n;
string s;
ll x=0, y=0;

void init(int sz) {
    for(int i=0; i<sz; i++) {
        if(s[i] == 'U') y++;
        else if(s[i] == 'D') y--;
        else if(s[i] == 'L') x--;
        else x++;
    }
}

bool check(ll mid) {
    x=0, y=0;

    init(n);
    x *= (mid/n);
    y *= (mid/n);
    init(mid % n);

    ll dist = abs((x + a.first) - b.first) + abs((y + a.second) - b.second);
    return (mid >= dist);
}

int main() {
    setIO();

    cin >> a.first >> a.second >> b.first >> b.second;
    ll ans = -1;
    cin >> n >> s;

    ll l=1, r=1e16;
    while(l <= r) {
        auto mid = l + (r - l) / 2;
    
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}