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

vector<pair<ull, ull> > intervals;

bool check(ull mid, int cows) {
   ull cnt = 1, itCount = 0, curr = intervals[0].first;

   while(curr + mid <= intervals.back().second) {
    while(curr + mid > intervals[itCount].second) {
        itCount++;
    }
    curr = max(curr + mid, intervals[itCount].first);
    cnt++;
   }

   return (cnt >= cows);
}

int main() {
    setIO("socdist");

    int n, m;
    ull ans = 0;
    cin >> n >> m; 

    for(int i=0; i<m; i++) {
        ull a, b;
        cin >> a >> b;
        intervals.push_back({ a, b });
    }

    sort(intervals.begin(), intervals.end());

    ull l=1, r=intervals[m-1].second - intervals[0].first + 1;
    while(l <= r) {
        auto mid = l + (r - l) / 2;
    
        if(check(mid, n)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}