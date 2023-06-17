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

struct Point
{
    int x;
    int y;

    ll dist(Point &p) {
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
    }
};

vector<Point> cows;
vector<bool> vis;

int dfs(int node, int maxDist) {
    vis[node] = true;
    int sum = 1;

    for(int i=0; i<cows.size(); i++) {
        if(vis[i]) continue;
        if(cows[node].dist(cows[i]) > maxDist) continue;
        sum += dfs(i, maxDist);
    }

    return sum;
}

bool check(ll mid, int n) {
    fill(vis.begin(), vis.end(), false);
    int total = dfs(0, mid);
    return (n == total);
}

int main() {
    setIO("moocast");

    int n;
    ll ans = 0;
    cin >> n;
    cows.resize(n);
    vis.resize(n, false);
    for(Point &p : cows) cin >> p.x >> p.y;

    ll l=0, r=25000*25000;
    while(l <= r) {
        auto mid = l + (r - l) / 2;
    
        if(check(mid, n)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}