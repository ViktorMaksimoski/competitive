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

vector<pair<int, int> > cows;
vector<bool> vis;
vector<vector<int> > graph;
int x1 = 1e9, y = 1e9, x2 = 0, y2 = 0;

struct Rect {
    int x1, y, x2, y2;

    Rect(int a, int b, int c, int d) {
        this->x1 = a;
        this->y = b;
        this->x2 = c;
        this->y2 = d;
    }

    ll perimeter() {
        return 2 * (x2 - x1) + 2 * (y2 - y);
    }
};

void dfs(int node) {
    vis[node] = true;
    x1 = min(x1, cows[node].first);
    x2 = max(x2, cows[node].first);
    y = min(y, cows[node].second);
    y2 = max(y2, cows[node].second);
    
    for(int &next : graph[node])
        if(!vis[next]) dfs(next);
}

int main() {
    setIO("fenceplan");

    int n, m;
    ll ans = 1e11;
    cin >> n >> m;
    graph.resize(n);
    vis.resize(n, false);

    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        cows.push_back({ a, b });
    }

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        dfs(i);
        Rect rect(x1, y, x2, y2);
        ans = min(ans, rect.perimeter());
        
        x1 = 1e9; y = 1e9;
        x2 = 0; y2 = 0;
    }

    cout << ans << '\n';
    return 0;
}