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

priority_queue<int, vector<int>, greater<int> > pq;

template <class T>
T getTop() {
    T node = pq.top();
    pq.pop();
    return node;
}

int main() {
    setIO();

    int x, n;
    cin >> x >> n;
    ll ans = 0;

    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }

    while(!pq.empty()) {
        if(pq.size() == 1) break;
        int a = getTop<int>(), b = getTop<int>();
        ans += (a + b);
        pq.push(a + b);
    }

    cout << ans << '\n';
    return 0;
}