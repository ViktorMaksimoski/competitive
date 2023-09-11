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
vector<int> pop;
vector<ll> sub;
int ans = -1;
ll currBest = 1e9;

void getSub(int u, int p) {
    sub[u] += pop[u];

    for(int &v : graph[u]) {
        if(v == p) continue;
        getSub(v, u);
        sub[u] += sub[v];
    }
}

void dfs(int u, int p) {
    ll here = sub[0] - sub[u];

    for(int &v : graph[u]) {
        if(v == p) continue;
        here = max(here, sub[v]);
    }

    if(here < currBest) {
        currBest = here;
        ans = u;
    }

    //cout << u << " " << here << '\n';

    for(int &v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
    }
}

int LocateCentre(int n, int p[], int s[], int d[]) {
    pop.resize(n);
    graph.resize(n);
    sub.resize(n, 0);

    for(int i=0; i<n; i++) pop[i] = p[i];

    for(int i=0; i<n-1; i++) {
        graph[s[i]].push_back(d[i]);
        graph[d[i]].push_back(s[i]);
    }

    getSub(0, 0);
    dfs(0, 0);
    //cout << currBest << '\n';
    return ans;
}

// int32_t main() {
//     setIO();

//     int n;
//     cin >> n;
//     vector<int> p(n);
//     vector<int> s(n);
//     vector<int> d(n);

//     for(int &x : p) cin >> x;

//     for(int i=0; i<n-1; i++) {
//         cin >> s[i] >> d[i];
//     }

//     cout << LocalCentre(n, p, s, d) << '\n';
//     return 0;
// }