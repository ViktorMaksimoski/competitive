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
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<vector<int> > graph;
vector<int> cycles;
vector<int> vis;
vector<int> st;
vector<vector<int> > rec;

void resize(int n) {
    graph.clear();
    graph.resize(n+1);
    cycles.clear();
    vis.clear();
    vis.resize(n+1, 0);
    st.clear();
    rec.clear();
} 

void dfs(int u, int p) {
    vis[u] = 1;
    st.push_back(u);

    for(int &v : graph[u]) {
        if(vis[v] == 0) {
            dfs(v, u);
        } else if(vis[v] == 1) {
            int cnt = 1;
            vector<int> v2 = {v};
            int pos = sz(st) - 1;
            while(pos && st[pos] != v) v2.push_back(st[pos]), cnt++, pos--;
            cycles.push_back(cnt);
            rec.push_back(v2);
        }
    }

    vis[u] = 2;
    st.pop_back();
}

void solve() {
    int n;
    cin >> n;
    resize(n);

    vector<pii> edges;

    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        graph[i].push_back(x);
        edges.push_back({ i, x });
    }

    for(int i=1; i<=n; i++) {
        if(vis[i]) continue;
        dfs(i, -1);
    }


    if(sz(cycles) == 1 && cycles[0] >= 3) {
        cout << "B\n";
    } else {
        int cnt = 0;
        for(int &x : cycles)
            cnt += (x == 2);

        if(cnt >= 2) {
            cout << "A\n";
        } else {
           bool ok = 0;

           for(int i=0; i<sz(cycles); i++) {
                if(cycles[i] != 2) continue;
                for(pii &x : edges) {
                    if(x.first == rec[i][0] && x.second == rec[i][1]) continue;
                    if(x.first == rec[i][1] && x.second == rec[i][0]) continue;
                    if(x.second != rec[i][0] && x.second != rec[i][1]) {
                        ok = 1;
                        break;
                    }
                }
                break;
           }

           if(ok) cout << "A\n";
           else cout << "BOTH\n";
        }
    }
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}