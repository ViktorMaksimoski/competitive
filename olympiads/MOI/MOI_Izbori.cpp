#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair
 
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
 
int n;
vector<set<int> > graph;
vector<bool> vis;
map<pii, vector<int> > triples;
bool mat[30][30];
 
void cnt() {
    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
 
        for(const int &j : graph[i]) {
            if(vis[j]) continue;
            for(const int &k : graph[j]) {
                if(vis[k]) continue;
                if(k != i && graph[i].count(k) && j < k)
                    triples[mp(i, j)].pb(k);
            }
        }
 
        vis[i] = true;
    }
}
 
int32_t main() {
    setIO();
 
    int m;
    cin >> n >> m;
    graph.resize(n);
    vis.resize(n, 0);
 
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        mat[a][b] = mat[b][a] = 1;
        graph[a].insert(b);
        graph[b].insert(a);
    }
 
    if(n <= 20) {
        cnt();
        int ans = 0;
        for(int s=0; s<(1<<n); s++) {
            bool ok = true;
            if(__builtin_popcount(s) < 3) {
                ans++;
                continue;
            }
 
            for(int i=0; i<n-2; i++) {
                if(!ok) break;
                if(s & (1 << i)) {
                    for(int j=i+1; j<n-1; j++) {
                        if(!ok) break;
                        if(s & (1 << j)) {
                            for(const int &k : triples[mp(i, j)]) {
                                if(s & (1 << k)) {
                                    ok = false;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            ans += ok;
        }
 
        cout << ans << '\n';
        return 0;
    }

    ll ans = 0;
    vector<int> masks;
    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            for(int k=j+1; k<n; k++) {
                if(mat[i][j] && mat[j][k] && mat[i][k]) {
                    int mask = 0;
                    mask |= (1 << i);
                    mask |= (1 << j);
                    mask |= (1 << k);
                    masks.push_back(mask);
                }
            }
        }
    }
 
    for(int s=1; s<(1<<sz(masks)); s++) {
        int mask = 0;
        for(int i=0; i<sz(masks); i++) {
            if(s & (1 << i)) {
                mask |= masks[i];
            }
        }
        if(__builtin_popcount(s) % 2 == 0)
            ans -= (1 << (n - __builtin_popcount(mask)));
        else
            ans += (1 << (n - __builtin_popcount(mask)));
    }
 
    //cout << sz(masks) << '\n';
    cout << (1 << n) - ans << '\n';
    return 0;
}