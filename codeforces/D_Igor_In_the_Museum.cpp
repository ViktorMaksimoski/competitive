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

int dr[8] = {0, -1, 0, 1, 1, 1, -1, -1};
int dc[8] = {-1, 0, 1, 0, 1, -1, 1, -1};
int n, m, k;
char mat[1000][1000];
bool vis[1000][1000];
int cnt = 0, curr = 1;
int comp[1000][1000];
vector<int> ans(1);

void dfs(int r, int c) {
    vis[r][c] = 1;
    comp[r][c] = curr;

    for(int i=0; i<4; i++) {
        int newR = r + dr[i];
        int newC = c + dc[i];
        if(newR < 0 || newR >= n) continue;
        if(newC < 0 || newC >= m) continue;
        if(vis[newR][newC]) continue;
        
        if(mat[newR][newC] == '*') {
            cnt++;
            continue;
        }

        dfs(newR, newC);
    } 
}

int32_t main() {
    setIO();

    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> mat[i][j];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == '*' || vis[i][j]) continue;
            cnt = 0;
            dfs(i, j);
            curr++;
            ans.push_back(cnt);
        }
    }

    while(k--) {
        int r, c;
        cin >> r >> c;
        cout << ans[comp[r-1][c-1]] << '\n';
    }

    return 0;
}