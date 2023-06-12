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

vector<vector<int> > graph;

template <class T>
struct DSU {
    vector<T> parent;
    vector<int> size;
    int components;

    DSU(int n) {
        parent.resize(n+1);
        for(int i=0; i<n+1; i++) parent[i] = i;
        size.resize(n+1, 1);
        components = n;
    }

    T find(T x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool uni(T a, T b) {
        T leaderA = find(a), leaderB = find(b);

        if(leaderA == leaderB) {
            return false;
        }

        components--;

        if(size[leaderA] > size[leaderB]) swap(leaderA, leaderB);

        parent[leaderA] = leaderB;
        size[leaderB] += size[leaderA];
        return true;
    }

    int getComponents() {
        return components;
    }
};

int main() {
    setIO("closing");
    
    int n, m;
    cin >> n >> m;
    graph.resize(n+1);

    for(int i=0; i<m; i++) {
         int a, b;
         cin >> a >> b;
         graph[a].push_back(b);
         graph[b].push_back(a);
    }

    DSU<int> dsu(n);
    vector<int> v(n);
    vector<string> ans;
    set<int> s;
    for(int &x : v) cin >> x;
    reverse(v.begin(), v.end());
    s.insert(v[0]);

    for(int i=1; i<n; i++) {
        for(int &j : graph[v[i]]) {
            if(s.count(j)) dsu.uni(v[i], j);
        }
        s.insert(v[i]);
        //cout << v[i] << ": " << dsu.getComponents() << '\n';
        if(dsu.getComponents() == n-i) ans.push_back("YES");
        else ans.push_back("NO");
    }

    reverse(ans.begin(), ans.end());
    ans.push_back("YES");
    for(string &s : ans) cout << s << '\n';
    return 0;
}