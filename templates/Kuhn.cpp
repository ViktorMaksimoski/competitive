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

//! number of elements in both sets (left and right)
int L, R;
vector<vector<int> > graph;
bool vis[101];

//! side_of[i] = j means that element i from the other set is already
//! connected to element j from thi set
vector<int> left_of, right_of;

bool find_match(int &node) {
    if(vis[node]) return false;
    vis[node] = true;

    //! try to find note from the other set that is free
    for(int &next : graph[node]) {
        if(left_of[next] != -1) continue;
        left_of[next] = node;
        right_of[node] = next;
        return true;
    }

    //! else try to reconnect some node from th other set
    //! and connect it to this node
    for(int &next : graph[node]) {
        int curr = left_of[next];
        if(find_match(curr)) {
            left_of[next] = node;
            right_of[node] = next;
            return true;
        }
    }

    return false;
}

//! tries to connect every node in one set (doesn't depend if it is L or R)
//! @return number of successfull "connections"
int kuhn() {
    fill(left_of.begin(), left_of.end(), -1);
    fill(right_of.begin(), right_of.end(), -1);

    int matched = 0;

    for(int i=0; i<L; i++) {
        memset(vis, false, sizeof(vis));
        matched += find_match(i);
    }

    return matched;
}

int main() {
    setIO();

    cin >> L >> R;
    graph.resize(L);
    left_of.resize(R);
    right_of.resize(L);

    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int matched = kuhn();
    cout << "Matched " << matched << " elements!" << '\n';
    return 0;
}