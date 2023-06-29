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
    int tc=1;
    while(true) {
        int n, s;
        cin >> n;
        if(!n) break;
        cin >> s;

        vector<vector<int> > graph(n+1);
        vector<int> indegree(n+1, 0);

        int a=1, b=1;
        while(a && b) {
            cin >> a >> b;
            graph[a].push_back(b);
            indegree[b]++;
        }

        queue<int> q;
        vector<int> topo;
        vector<int> dp(n+1, -1);
        for(int i=1; i<=n; i++)
            if(!indegree[i]) q.push(i);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);
            for(int &next : graph[node]) {
                indegree[next]--;
                if(!indegree[next]) q.push(next);
            }
        }


        dp[s] = 0;
        for(int &v : topo) {
            for(int &u : graph[v]) {
                dp[u] = max(dp[u], dp[v] + 1);
            }
        }

        int ans = 1;
        for(int i=2; i<=n; i++)
            if(dp[i] > dp[ans]) ans = i;

        cout << "Case " << tc++ << ": " << "The longest path from ";
        cout << s << " has length " << dp[ans] << ", finishing ";
        cout << "at " << ans << "." << '\n' << '\n';
        
    }

    return 0;
}