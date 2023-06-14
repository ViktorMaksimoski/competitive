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

bool check(int stage, vector<int> &cows, int t) {
    int total = 0;
    //cout << "stage: " << stage << '\n';
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<stage; i++) pq.push(cows[i]);
    int id = stage;

    while(!pq.empty()) {
        total += max(0, pq.top() - total);
        //cout << pq.top() << '\n';
        pq.pop();
        if(id < cows.size()) {
            pq.push(total + cows[id]);
            id++;
        }
    }
   
    //cout << total << '\n';
    return (total <= t);
}

int main() {
    setIO("cowdance");

    int n, t, ans = 0;
    cin >> n >> t;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    int l=1, r=n;
    while(l <= r) {
        auto mid = l + (r - l) / 2;
    
        if(check(mid, v, t)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}