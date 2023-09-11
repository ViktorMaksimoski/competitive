#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
//#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    setIO();

    int n;
    int caseId = 1;
    while(cin >> n) {
        map<string, int> val;
        map<int, string> reval;
        int id = 1;

        for(int i=0; i<n; i++) {
            string s;
            cin >> s;
            reval[id] = s;
            val[s] = id++;
        }

        int m;
        cin >> m;

        vector<int> topo;
        priority_queue<int, vector<int>, greater<int> > pq;
        vector<vector<int> > graph(n+1);
        vector<int> indegree(n+1);

        for(int i=0; i<m; i++) {
            string a, b;
            cin >> a >> b;
            graph[val[a]].push_back(val[b]);
            indegree[val[b]]++;
        }

        for(int i=1; i<=n; i++)
            if(!indegree[i]) pq.push(i);

        while(!pq.empty()) {
            int u = pq.top();
            pq.pop();

            topo.push_back(u);

            for(int &v : graph[u]) {
                indegree[v]--;
                if(!indegree[v]) pq.push(v);
            }
        }

        cout << "Case #" << caseId++ << ": ";
        cout << "Dilbert should drink beverages in this order:";
        for(int &x : topo) cout << " " << reval[x];
        cout << ".\n";
        cout << '\n';
    }

    return 0;
}