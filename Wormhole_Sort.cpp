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

    T getSize(T x) {
        return size[find(x)];
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

struct Edge {
    int from;
    int to;
    int weight;
};

bool cmp(Edge &a, Edge &b) {
    return (a.weight < b.weight);
}

int main() {
    setIO("wormsort");

    int n, m, ans = -1;
    cin >> n >> m;
    vector<int> cows(n);
    vector<Edge> edges(m);
    for(int &x : cows) cin >> x;
    for(int &x : cows) x--;
    for(Edge &e : edges) cin >> e.from >> e.to >> e.weight;
    for(Edge &e : edges) e.from--, e.to--;

    sort(edges.begin(), edges.end(), cmp);
    DSU<int> dsu(n);
    
    int edge = m;
    for(int i=0; i<n; i++) {
        if(dsu.find(i) != dsu.find(cows[i])) {
            edge--;
            dsu.uni(edges[edge].from, edges[edge].to);
        }
    }

    //cout << edge << '\n';
    if(edge < m) ans = edges[edge].weight;
    cout << ans << '\n';
    return 0;
}