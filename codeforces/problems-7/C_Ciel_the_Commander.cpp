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

int n;
vector<vector<int> > graph;
vector<int> sub;
vector<bool> deleted;
vector<char> ans;

int get_sub(int u, int p) {
    sub[u] = 1;
    for(int &v : graph[u]) {
        if(v == p || deleted[v]) continue;
        sub[u] += get_sub(v, u);
    }
    return sub[u];
}

int get_centroid(int u, int p, int sz) {
    for(int &v : graph[u]) {
        if(v == p || deleted[v]) continue;
        if(2 * sub[v] > sz)
            return get_centroid(v, u, sz);
    }
    return u;
}

void decomp(int u, int p, char ch) {
    int centroid = get_centroid(u, u, get_sub(u, u));
    //cout << centroid << '\n';
    ans[centroid] = ch;
    deleted[centroid] = 1;

    for(int &v : graph[centroid]) {
        if(deleted[v]) continue;
        ch++;
        decomp(v, centroid, ch);
        ch--;
    }
}

int32_t main() {
    setIO();

    cin >> n;
    graph.resize(n+1);
    sub.resize(n+1);
    deleted.resize(n+1, 0);
    ans.resize(n+1, 'A');

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    decomp(1, 1, 'A');

    for(int i=1; i<=n; i++) cout << ans[i] << " ";
    return 0;
}