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

set<int> unvis;
vector<set<int> > graph;

int dfs(int node) {
    int sum = 1;
    unvis.erase(node);
    auto it = unvis.begin();

    while(it != unvis.end()) {
        if(graph[node].count(*it)) {
            it++;
        } else {
            int next = *it;
            sum += dfs(next);
            it = unvis.upper_bound(next);
        }
    }

    return sum;
}

int main() {
    setIO();

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        unvis.insert(i);
    graph.resize(n+1);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    vector<int> ans;

    for(int i=1; i<=n; i++) {
        if(!unvis.count(i)) continue;
        ans.emplace_back(dfs(i));
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int &x : ans) cout << x << " ";
    return 0;
}