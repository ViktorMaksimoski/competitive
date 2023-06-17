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

int n;
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
        return size[leaderB] >= (n*n + 1) / 2;
    }

    int getComponents() {
        return components;
    }

    bool same_set(T a, T b) {
        return find(a) == find(b);
    }
};

int get_code(int a, int b) {
    return a*n + b;
}

struct Edge
{
    int a, b, w;
    void print() {
        cout << a << " - " << b << " - " << w << '\n';
    }
};

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

bool cmp(Edge &a, Edge &b) {
    return (a.w < b.w);
}

int main() {
    setIO("tractor");

    cin >> n;
    vector<vector<int> > mat(n, vector<int>(n, 0));
    for(vector<int> &v : mat)
        for(int &x : v) cin >> x;

    vector<Edge> edges;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<4; k++) {
                int newI = i + dr[k], newJ = j + dc[k];
                if(newI < 0 || newI >= n || newJ < 0 || newJ >= n) continue;
                if(mat[i][j] < mat[newI][newJ]) continue;
                Edge edge;
                edge.a = get_code(i, j);
                edge.b = get_code(newI, newJ);
                edge.w = abs(mat[i][j] - mat[newI][newJ]);
                edges.push_back(edge);
            }
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    DSU<int> dsu(n*n);
    for(Edge &edge : edges) {
        if(dsu.uni(edge.a, edge.b)) {
            cout << edge.w << '\n';
            return 0;
        }
    }

    return 0;
}