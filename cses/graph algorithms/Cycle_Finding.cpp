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

int main() {
    setIO();

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > graph(n+1);
    vector<ll> dist(n+1, 1e13);
    vector<int> source(n+1, -1);

    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
    }

    dist[1] = 0;
    int x = -1;
    for(int it=0; it<n; it++) {
        x = -1;
        for(int node=1; node<=n; node++) {
            for(auto &next : graph[node]) {
                if(dist[next.first] > dist[node] + next.second) {
                    source[next.first] = node;
                    dist[next.first] = dist[node] + next.second;
                    x = next.first;
                }
            }
        }
    }


    if(x == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<int> cycle;
        for(int i=0; i<n; i++)
            x = source[x];

        for(int v=x; ; v=source[v]) {
            cycle.push_back(v);
            if(v == x && cycle.size() > 1) break;
        }

        reverse(cycle.begin(), cycle.end());
        for(int &v : cycle) cout << v << " ";
    }
    return 0;
}