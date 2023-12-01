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

void solve() {
    int n;
    cin >> n;

    int mat[3][n];
    map<int, int> cnt[3];
    map<int, vector<int> > pos[3];

    for(int i=0; i<3; i++) {
        for(int j=0; j<n; j++) {
            cin >> mat[i][j];
            cnt[i][mat[i][j]]++;
            pos[i][mat[i][j]].push_back(j);
        }
    }

    int ans = 0;

    vector<bool> vis(n);
    queue<int> q;

    for(int i=1; i<=n; i++) {
        int mn = 1e9;
        for(int j=0; j<3; j++) 
            mn = min(mn, cnt[j][i]);
        if(!mn) q.push(i);
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i=0; i<3; i++) {
            for(int &v : pos[i][u]) {
                if(vis[v]) continue;
                for(int j=0; j<3; j++) {
                    if(i == j) continue;
                    cnt[j][mat[j][v]]--;
                    if(!cnt[j][mat[j][v]]) q.push(mat[j][v]);
                }
                vis[v] = 1;
                ans++;
            }
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}