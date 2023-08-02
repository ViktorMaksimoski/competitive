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
    vector<int> size, minimal, maximal;
    int components;

    DSU(int n) {
        parent.resize(n+1);
        minimal.resize(n+1);
        maximal.resize(n+1);
        for(int i=0; i<n+1; i++) minimal[i] = i;
        for(int i=0; i<n+1; i++) maximal[i] = i;
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

        minimal[leaderB] = min(minimal[leaderB], minimal[leaderA]);
        maximal[leaderB] = max(maximal[leaderB], maximal[leaderA]);
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

    void print(int a) {
        int lead = find(a);
        cout << minimal[lead] << " " << maximal[lead] << " " << size[lead] << '\n';
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
        if(s[0] == 'u') {
            int a, b;
            cin >> a >> b;
            dsu.uni(a, b);
        } else {
            int a;
            cin >> a;
            dsu.print(a);
        }
    }

    return 0;
}