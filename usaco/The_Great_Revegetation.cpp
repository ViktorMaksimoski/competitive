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

vector<vector<pair<int, bool>> > graph;
vector<int> color;
vector<bool> vis;

int main() {
    setIO("revegetate");

    int n, m;
    cin >> n >> m;
    graph.resize(n);
    vis.resize(n, false);
    color.resize(n, -1);

    for(int i=0; i<m; i++) {
        char ch;
        int a, b;
        cin >> ch >> a >> b;
        a--;
        b--;
        graph[a].push_back(make_pair(b, ch == 'S' ));
        graph[b].push_back(make_pair(a, ch == 'S' ));
    }

    int comp = 0;
    bool pos = true;

    for(int i=0; i<n; i++) {
        if(vis[i] || color[i] > -1) continue;
        comp++;
        queue<pair<int, bool> > q;
        q.push({ i, true });
        vis[i] = true;

        while(!q.empty()) {
            pair<int, bool> node = q.front();
            q.pop();
            color[node.first] = node.second;

            for(auto &next : graph[node.first]) {
                bool type = next.second ? node.second : !node.second;

                if(color[next.first] == -1) {
                    q.push({ next.first, type });
                    vis[next.first] = true;
                } else if(color[next.first] == !type) {
                    pos = false;
                    break;
                }
            }
        }

    }

    if(!pos) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << 1;
        for(int i=0; i<comp; i++) cout << 0;
        cout << '\n';
    }

    return 0;
}