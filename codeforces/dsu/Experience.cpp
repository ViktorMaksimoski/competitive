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
    vector<ll> points, add;
    int components;

    DSU(int n) {
        parent.resize(n+1);
        for(int i=0; i<n+1; i++) parent[i] = i;
        size.resize(n+1, 1);
        points.resize(n+1, 0);
        add.resize(n+1, 0);
        components = n;
    }

    T find(T x) {
        if(parent[x] == x) return x;
        return find(parent[x]);
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
        add[leaderA] -= add[leaderB];
        return true;
    }

    int getComponents() {
        return components;
    }

    bool same_set(T a, T b) {
        return find(a) == find(b);
    }

    ll getPoints(T a) {
        if(parent[a] == a)
            return add[a];
        return add[a] + getPoints(parent[a]);
    }

    void addPoints(T a, T b) {
        add[find(a)] += b;
    }
};

int main() {
    setIO();

    int n, q;
    cin >> n >> q;
    DSU<int> dsu(n);

    while(q--) {
        string s;
        cin >> s;

        if(s[0] == 'j') {
            int a, b;
            cin >> a >> b;
            dsu.uni(a, b);
        } else if(s[0] == 'a') {
            int a, b;
            cin >> a >> b;
            dsu.addPoints(a, b);
        } else {
            int a;
            cin >> a;
            cout << dsu.getPoints(a) << '\n';
        }
    }

    return 0;
}