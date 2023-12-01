#include <bits/stdc++.h>
 
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
//#define int long long
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;
 
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
 
int L, R;
vector<vector<int> > graph;
vector<int> left_of, right_of;
vector<bool> vis;
 
bool find_match(int u) {
    if(vis[u]) return false;
    vis[u] = true;
 
    for(int &v : graph[u]) {
        if(left_of[v] != -1) continue;
        left_of[v] = u;
        right_of[u] = v;
        return true;
    }
 
    for(int &v : graph[u]) {
        if(left_of[v] == -1) continue;
        if(find_match(left_of[v])) {
            left_of[v] = u;
            right_of[u] = v;
            return true;
        }
    }
 
    return false;
}
 
int kuhn(int n) {
    int ans = 0;
 
    for(int i=0; i<n; i++) {
        fill(all(vis), 0);
        ans += find_match(i);
    }
 
    return ans;
}
 
int32_t main() {
    setIO();
 
    int n;
    cin >> n;
 
    graph.resize(n);
    left_of.resize(n, -1);
    right_of.resize(n, -1);
    vis.resize(n);
 
    vector<int> v(n);
    for(int &x : v) cin >> x;
 
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) continue;
            if(__gcd(v[i], v[j]) != 1) continue;
            ll res = 1ll * v[i] * v[i] + 1ll * v[j] * v[j];
            if(sqrt(res) != (ll)sqrt(res)) continue;
            graph[i].push_back(j);
        }
    }
 
    cout << kuhn(n) << '\n';
    return 0;
}