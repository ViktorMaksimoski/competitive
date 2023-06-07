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

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.second.second > b.second.second;
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

int main() {
    setIO("mootube");

    int n, q;
    cin >> n >> q;

    vector<pair<int, pair<int, int>> > edges(n-1), queries(q);
    vector<int> ans(q);
    DSU<int> dsu(n);  

    for(int i=0; i<n-1; i++) {
         int a, b, w;
         cin >> a >> b >> w;
         a--; b--;
         edges[i] = {w, {a, b}};
    }

    for(int i=0; i<q; i++) {
        cin >> queries[i].second.second >> queries[i].second.first;
        queries[i].second.first -= 1;
        queries[i].first = i;
    }

    sort(queries.begin(), queries.end(), cmp);
    sort(edges.begin(), edges.end(), greater<pair<int, pair<int, int>> > ());

    int id = 0;
    for(int query=0; query<q; query++) {
        int video = queries[query].second.first;
        int res = queries[query].second.second;

        while(id < n-1 && edges[id].first >= res) {
            dsu.uni(edges[id].second.first, edges[id].second.second);
            id++;
        }
        ans[queries[query].first] = dsu.getSize(video) - 1; 
    }

    for(int &x : ans) cout << x << '\n';
    return 0;
}