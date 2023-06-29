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

int n[2], m[2];
vector<vector<int> > graph[2];
vector<int> indegree[2];
vector<int> topo[2];
vector<set<int> > dp[2];

void getTopo(int a) {
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i=1; i<=n[a]; i++)
        if(!indegree[a][i]) q.push(i);

    while(!q.empty()) {
        int node = q.top();
        q.pop();

        topo[a].push_back(node);
        for(int &next : graph[a][node]) {
            indegree[a][next]--;
            if(!indegree[a][next]) q.push(next);
        }
    }

    dp[a][1].insert(0);
    for(int &u : topo[a]) {
        for(int &v : graph[a][u]) {
            for(const int &x : dp[a][u]) {
                dp[a][v].insert(x+1);
            }
        }
    }


}

int main() {
    setIO();
 
    cin >> n[0] >> n[1] >> m[0] >> m[1];
    graph[0].resize(n[0]+1);
    graph[1].resize(n[1]+1);
    indegree[0].resize(n[0]+1, 0);
    indegree[1].resize(n[1]+1, 0);
    dp[0].resize(n[0]+1);
    dp[1].resize(n[1]+1);

    for(int i=0; i<m[0]; i++) {
        int a, b;
        cin >> a >> b;
        graph[0][a].push_back(b);
        indegree[0][b]++;
    }

    for(int i=0; i<m[1]; i++) {
        int a, b;
        cin >> a >> b;
        graph[1][a].push_back(b);
        indegree[1][b]++;
    }

    getTopo(0);
    getTopo(1);

    set<int> pos_ans;

    for(const int &x1 : dp[0][n[0]]) {
        for(const int &x2 : dp[1][n[1]]) {
            pos_ans.insert(x1 + x2);
        }
    }

    int q;
    cin >> q;
    
    while(q--) {
        int a;
        cin >> a;

        if(pos_ans.count(a)) cout << "Yes";
        else cout << "No";
        cout << '\n';
    }

    return 0;
}