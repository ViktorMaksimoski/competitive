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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > graph(n);
    vector<bool> vis(n, false);
    vector<int> dist(n, 1e9);

    for(int i=0; i<m; i++) {
         int a, b;
         cin >> a >> b;
         a--; b--;
         graph[a].push_back(b);
         graph[b].push_back(a);
    }

    queue<int> q;
    q.push(0);
    dist[0] = 0;
    vis[0] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int &next : graph[node]) {
            if(vis[next]) continue;
            vis[next] = true;
            dist[next] = dist[node] + 1;
            q.push(next);
        }
    }

    vector<int> even, odd;
    for(int i=0; i<n; i++) {
        if(dist[i] % 2 == 0) even.push_back(i+1);
        else odd.push_back(i+1);
    }

    if(even.size() < odd.size()) {
        cout << even.size() << '\n';
        for(int &x : even) cout << x << " ";
    } else {
        cout << odd.size() << '\n';
        for(int &x : odd) cout << x << " ";
    }
    cout << '\n';
}

int main() {
    setIO();

    int tc;
    cin >> tc;

    while(tc--)
        solve();

    return 0;
}