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

int dr[8] = {0, -1, 0, 1, -1, -1, 1, 1};
int dc[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int n, m, comp=0, curr = 1;

char mat[51][51];
bool vis[51][51];
int col[51][51];

set<int> x, y;

void dfs(int r, int c) {
    comp++;
    x.insert(r);
    y.insert(c);
    vis[r][c] = 1;
    col[r][c] = curr;

    for(int i=0; i<4; i++) {
        int newR = r + dr[i];
        int newC = c + dc[i];
        if(newR < 0 || newR >= n) continue;
        if(newC < 0 || newC >= m) continue;
        if(mat[newR][newC] == '.' || vis[newR][newC]) continue;
        dfs(newR, newC);
    }
}

void solve() {
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    memset(col, 0, sizeof(col));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> mat[i][j];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(vis[i][j] || mat[i][j] == '.') continue;
            x.clear(); y.clear(); comp = 0;
            dfs(i, j);
            curr++;
            if(comp != 3 || x.size() != 2 || y.size() != 2) {
                cout << "NO\n";
                return ;
            } 
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == '.') continue;
            for(int k=4; k<8; k++) {
                int newR = i + dr[k];
                int newC = j + dc[k];
                if(newR < 0 || newR >= n) continue;
                if(newC < 0 || newC >= m) continue;
                if(mat[newR][newC] == '.') continue;
                if(col[i][j] != col[newR][newC]) {
                    cout << "NO\n";
                    return ;
                }
            }
        }
    }

    cout << "YES\n";
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}