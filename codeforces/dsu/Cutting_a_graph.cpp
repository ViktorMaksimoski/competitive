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

struct Query
{
    bool type;
    int a, b;
};


int main() {
    setIO();

    int n, m, q;
    cin >> n >> m >> q;
    DSU<int> dsu(n);

    while(m--) {
        int a, b;
        cin >> a >> b;
    }

    vector<Query> queries;
    while(q--) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        queries.push_back(Query{(s == "cut"), a, b});
    }

    reverse(queries.begin(), queries.end());

    stack<bool> s;
    for(Query q : queries) {
        if(q.type) {
            dsu.uni(q.a, q.b);
        } else {
            s.push(dsu.same_set(q.a, q.b));
        }
    }

    while(!s.empty()) {
        bool ans = s.top();
        s.pop();
        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}