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

int main() {
    setIO();

    int n, q;
    cin >> n >> q;
    DSU<int> dsu(n);
    set<int> s;
    for(int i=1; i<n; i++)
        s.insert(i);
    s.insert(int(1e9));

    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;

        if(t == 1) {
            dsu.uni(a, b);
        } else if(t == 2) {
            vector<int> v;
            auto it = s.lower_bound(a);
            while((*it) < b) {
                v.push_back(*it);
                it++;
            }

            for(int &x : v)
                s.erase(x);
            for(int &x : v)
                dsu.uni(x, x+1);
        } else if(t == 3) {
            bool res = dsu.same_set(a, b);
            cout << (res ? "YES" : "NO") << '\n';
        }
    } 

    return 0;
}