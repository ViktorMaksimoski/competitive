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

int n, m;
int ans = 1e9 + 5*1e8;
vector<pair<int, int> > boots;
vector<int> tiles;
bool vis[251][251];

void dfs(int d, int b) {
    vis[d][b] = true;

    if(d == n-1) {
        ans = min(ans, b);
        return ;
    }

    //use this boot
    for(int i=1; i<=boots[b].second; i++)
        if(tiles[d+i] <= boots[b].first && d+i < n && !vis[d+i][b]) 
            dfs(d+i, b);

    //change boot here
    for(int i=b+1; i<m; i++)
        if(tiles[d] <= boots[i].first && !vis[d][i]) 
            dfs(d, i);
}

int main() {
    setIO("snowboots");

    cin >> n >> m;
    tiles.resize(n);
    boots.resize(m);
    memset(vis, false, sizeof(vis));

    for(int i=0; i<n; i++)
        cin >> tiles[i];
    for(int i=0; i<m; i++)
        cin >> boots[i].first >> boots[i].second;

    dfs(0, 0);
    cout << ans << '\n';
    return 0;
}