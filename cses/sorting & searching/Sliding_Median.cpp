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

multiset<int> small, big;

void insert(int val, int k) {
    int leftBest = *(--small.end());
    if(leftBest < val) {
        big.insert(val);
        if(big.size() > k/2) {
            small.insert(*big.begin());
            big.erase(big.find(*big.begin()));
        }
    } else {
        small.insert(val);
        if(small.size() > (k+1)/2) {
            big.insert(*(--small.end()));
            small.erase(small.find(*(--small.end())));
        }
    }
}

void erase(int val, int k) {
    if(small.find(val) != small.end()) small.erase(small.find(val));
    else big.erase(big.find(val));

    if(small.empty()) {
        small.insert(*big.begin());
        big.erase(big.find(*big.begin()));
        
    }
}

int main() {
    setIO();

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    small.insert(v[0]);
    for(int i=1; i<k; i++) insert(v[i], k);
    cout << *small.rbegin() << " ";

    for(int i=k; i<n; i++) {
        if(k == 1) {
            insert(v[i], k);
            erase(v[i-k], k);
        } else {
            erase(v[i-k], k);
            insert(v[i], k);
        }
        cout << *small.rbegin() << " ";
    }
    return 0;
}