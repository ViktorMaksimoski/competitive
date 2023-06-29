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
    vector<vector<int> > graph(n+1);
    vector<int> indegree(n+1, 0);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    //we can use PQ for lexicographically min/max topo sort
    //priority_queue<int, vector<int>, greater<int>> q;
    queue<int> q;
    vector<int> topo;
    for(int i=1; i<=n; i++)
        if(!indegree[i]) q.push(i);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for(int &next : graph[node]) {
            indegree[next]--;
            if(!indegree[next]) q.push(next);
        }
    }

    if(topo.size() != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << topo[0] << " ";
    for(int i=1; i<n; i++) cout << topo[i] << " ";
    return 0;
}