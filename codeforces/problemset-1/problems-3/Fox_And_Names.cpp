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

int main() {
    setIO();

    int n;
    cin >> n;
    vector<string> names(n);
    for(string &s : names) cin >> s;

    vector<vector<int> > graph(26);
    vector<int> indegree(26, 0);
    for(int i=0; i<n-1; i++) {
        int len = min(names[i].size(), names[i+1].size());
        bool ok = true;
        for(int j=0; j<len; j++) {
            if(names[i][j] == names[i+1][j]) continue;
            graph[names[i][j]-'a'].push_back(names[i+1][j]-'a');
            indegree[names[i+1][j]-'a']++;
            ok = false;
            break;
        }

        if(ok && names[i].size() > names[i+1].size()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    vector<int> topo;
    queue<int> q;
    for(int i=0; i<26; i++)
        if(!indegree[i]) q.push(i);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        topo.push_back(u);
        for(int &v : graph[u]) {
            indegree[v]--;
            if(!indegree[v]) q.push(v);
        }
    }

    if(topo.size() != 26) {
        cout << "Impossible\n";
        return 0;
    }

    for(int &u : topo)
        cout << char('a' + u);
    return 0;
}