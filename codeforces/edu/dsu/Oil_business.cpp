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

    bool same_set(T a, T b) {
        return find(a) == find(b);
    }
};

struct Edge {
    int w, a, b;
    int id;
};

bool cmp(Edge &a, Edge &b) {
    return (a.w < b.w);
}

int main() {
    setIO();

    int n, m;
    ull s;
    cin >> n >> m >> s;
    DSU<int> dsu(n);
    vector<Edge> edges(m);

    for(int i=0; i<m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        edges[i].id = i+1;
    }

    //we want to find the maximum spnning tree
    //then we try to remove edges that are'n in the MST
    sort(edges.begin(), edges.end(), cmp);    
    vector<int> used(m, 0);

    //kruskal
    for(int i=m-1; i>=0; i--) {
        if(dsu.uni(edges[i].a, edges[i].b))
            used[i] = 1;
    }

    ull sum = 0;
    for(int i=0; i<m; i++) {
        if(used[i] == 0) {
            if(sum + edges[i].w > s) break;
            used[i] = 2;
            sum += edges[i].w;
        }
    }

    int removed = 0;
    vector<int> ids;
    for(int i=0; i<m; i++)
        if(used[i] == 2) removed++, ids.push_back(edges[i].id);
    
    cout << removed << '\n';
    sort(ids.begin(), ids.end());
    for(int &x : ids) cout << x << " ";
    return 0;
}