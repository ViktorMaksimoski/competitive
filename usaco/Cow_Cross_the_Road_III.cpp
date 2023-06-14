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

int n, k, r;
set<array<int, 4>> roads;
map<pair<int, int>, int> hasCows;
int vis[101][101];
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

bool ok(int r, int c, int a, int b) {
    return (r >= 0 && r < n && c >= 0 &&
     c < n && !vis[r][c] && !roads.count({r, c, a, b}));
}

int dfs(int r, int c) {
    int sum = hasCows[make_pair(r, c)];
    vis[r][c] = true;

    for(int i=0; i<4; i++) {
        int newR = r + dr[i];
        int newC = c + dc[i];
        if(ok(newR, newC, r, c))
            sum += dfs(newR, newC);
    }

    return sum;
}

int main() {
    setIO("countcross");

    cin >> n >> k >> r; 
    memset(vis, false, sizeof(vis));

    ll ans = 0;
    for(int i=0; i<r; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        roads.insert({a, b, c, d});
        roads.insert({c, d, a, b});
    }

    for(int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        hasCows[make_pair(--a, --b)] = 1;
    }
    
    vector<int> comp;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(vis[i][j]) continue;
            int res = dfs(i, j);
            if(res > 0) comp.emplace_back(res);
        }
    }

    for(int i=0; i<comp.size()-1; i++)
        for(int j=i+1; j<comp.size(); j++)
            ans += (comp[i] * comp[j]);

    cout << ans << '\n';
    return 0;
}