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

vector<vector<int> > graph;
vector<int> vis;
vector<int> left_of, right_of;
int n, m;

bool find_match(int node) {
    if(vis[node]) return 0;
    vis[node] = true;

    for(int &next : graph[node]) {
        if(left_of[next] != -1) continue;
        left_of[next] = node;
        right_of[node] = next;
        return true;
    }

    for(int &next : graph[node]) {
        if(find_match(left_of[next])) {
            left_of[next] = node;
            right_of[node] = next;
            return true;
        }
    }

    return false;
}

int kuhn() {
    fill(left_of.begin(), left_of.end(), -1);
    fill(right_of.begin(), right_of.end(), -1);

    int ans = 0;

    for(int i=1; i<=n; i++) {
        fill(vis.begin(), vis.end(), false);
        ans += find_match(i);
    }

    return ans;
}

int main() {
    setIO();

    int k;
    cin >> n >> m >> k;
    graph.resize(n+1);
    vis.resize(n+1);
    left_of.resize(m+1, -1);
    right_of.resize(n+1, -1);

    for(int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int matched = kuhn();
    cout << matched << '\n';

    for(int i=1; i<=n; i++) {
        if(right_of[i] == -1) continue;
        cout << i << " " << right_of[i] << '\n';
    }

    return 0;
}