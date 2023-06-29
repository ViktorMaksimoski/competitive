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
    setIO("milkorder");

    int n, m;
    cin >> n >> m;
    vector<vector<int> > lists(m);

    for(int i=0; i<m; i++) {
        int x;
        cin >> x;
        while(x--) {
            int a;
            cin >> a;
            lists[i].push_back(a);
        }
    }

    int l=0, r=m-1;
    vector<int> topo, ans;
    while(l <= r) {
        int mid = (l + r) / 2;

        //construct graph based on first MID observations
        vector<vector<int> > graph(n+1);
        vector<int> indegree(n+1, 0);
        for(int i=0; i<=mid; i++) {
            for(int j=0; j<lists[i].size()-1; j++) {
                graph[lists[i][j]].push_back(lists[i][j+1]);
                indegree[lists[i][j+1]]++;
            }
        }

        priority_queue<int, vector<int>, greater<int> > q;
        topo.clear();
        for(int i=1; i<=n; i++)
            if(!indegree[i]) q.push(i);

        while(!q.empty()) {
            int node = q.top();
            q.pop();

            topo.push_back(node);
            for(int &next : graph[node]) {
                indegree[next]--;
                if(!indegree[next]) q.push(next);
            }
        }

        if(topo.size() == n) {
            ans = topo;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }



    for(int i=0; i<ans.size(); i++) {
        cout << ans[i];
        if(i == ans.size()-1) cout << '\n';
        else cout << " ";
    }

    return 0;
}