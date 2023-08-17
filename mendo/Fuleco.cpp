#include <bits/stdc++.h>
 
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair
#define int long long
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
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
 
vector<vector<int> > graph;
 
int32_t main() {
    setIO();
 
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    graph.resize(sz(s)/2+2);
 
    int id = 1;
    int t = 1;
 
    int valA = 0, valB = 0;
    stack<int> st;
    st.push(0);
    for(int i=0; i<sz(s); i++) {
        if(s[i] == 'U') {
           graph[st.top()].pb(id);
           graph[id].pb(st.top());
           st.push(id++);
        } else {
            st.pop();
        }
 
        if(t == a) {
            valA = st.top();
        }
        if(t == b) {
            valB = st.top();
        }
 
        t++;
    }
 
    queue<int> q;
    vector<int> dist(sz(s)/2+2, 0);
 
    q.push(valA);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
 
        for(int &x : graph[u]) {
            if(dist[x]) continue;
            q.push(x);
            dist[x] = dist[u] + 1;
        }
    }
 
    cout << dist[valB] << '\n';
    return 0;
}