#include <bits/stdc++.h>
#include <string>
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

int L, R;
vector<vector<int> > graph;
bool vis[101];

//! side_of[i] = j means that element i from the other set is already
//! connected to element j from thi set
vector<int> left_of, right_of;

bool find_match(int &node) {
    if(vis[node]) return false;
    vis[node] = true;

    for(int &next : graph[node]) {
        if(left_of[next] != -1) continue;
        left_of[next] = node;
        right_of[node] = next;
        return true;
    }

    for(int &next : graph[node]) {
        if(!find_match(left_of[next])) continue;
        left_of[next] = node;
        right_of[node] = next;
        return true;
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

    int n;
    cin >> n;
    vector<string> dice(n); 
    graph.resize(100);

    for(string &s : dice)
        cin >> s;

    string goal;
    cin >> goal;

    L = dice.size();
    R = goal.size();
    left_of.resize(n);
    right_of.resize(R);

    for(int i=0; i<n; i++) {
        for(int j=0; j<goal.size(); j++) {
            bool found = false;

            for(char &ch : dice[i]) {
                if(ch != goal[j]) continue;
                found = true;
                break;
            }

            if(found)
                graph[i].push_back(j);
        }
    }

    int ans = kuhn();
    cout << (ans == goal.size() ? "YES" : "NO") << '\n';
    if(ans != goal.size()) cout << ans << '\n';
    return 0;
}