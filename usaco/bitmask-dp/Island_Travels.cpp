#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()

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

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

//gospod napomos neka mi e so zadacava
//leten kamp, ama na steroidi
// Najdi ostrovi, presmetaj distanca megju site, TSP
int n, m;
int curr = 1;
char mat[50][50];
bool vis[50][50];
int comp[50][50];
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

void dfs(int r, int c) {
    comp[r][c] = curr;

    for(int i=0; i<4; i++) {
        int newR = r + dr[i];
        int newC = c + dc[i];
        if(newR < 0 || newR >= n) continue;
        if(newC < 0 || newC >= m) continue;
        if(vis[newR][newC]) continue;
        if(mat[newR][newC] != 'X') continue;
        vis[newR][newC] = true;
        dfs(newR, newC);
    }
}

int32_t main() {
    setIO();
    setUSA("island");

    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> mat[i][j];

    memset(vis, 0, sizeof(vis));
    memset(comp, 0, sizeof(comp));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == 'X' && !comp[i][j]) {
                vis[i][j] = true;
                dfs(i, j);
                curr++;
            }
        }
    }

    vector<vector<int> > dist(curr, vector<int>(curr, 1e9));
    vector<bool> seen(curr, 0);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] != 'X') continue;
            if(seen[comp[i][j]]) continue;
            dist[comp[i][j]][comp[i][j]] = 0;
            seen[comp[i][j]] = true;

            queue<pii> q;
            bool visBfs[n][m];
            int distBfs[n][m];
            memset(visBfs, 0, sizeof(visBfs));
            
            for(int row=0; row<n; row++)
                for(int col=0; col<m; col++)
                    distBfs[row][col] = 1e9;

            q.push({ i, j });
            visBfs[i][j] = true;
            distBfs[i][j] = 0;

            while(!q.empty()) {
                int r = q.front().first;
                int c = q.front().second;
                //cout << r << " " << c << endl;
                q.pop();

                if(mat[r][c] == 'X') {
                    dist[comp[i][j]][comp[r][c]] = min(
                        dist[comp[i][j]][comp[r][c]],
                        distBfs[r][c]
                    );

                    dist[comp[r][c]][comp[i][j]] = min(
                        dist[comp[r][c]][comp[i][j]],
                        dist[comp[i][j]][comp[r][c]]
                    );
                }

                for(int k=0; k<4; k++) {
                    int newR = r + dr[k];
                    int newC = c + dc[k];
                    if(newR < 0 || newR >= n) continue;
                    if(newC < 0 || newC >= m) continue;
                    if(visBfs[newR][newC]) continue;
                    if(mat[newR][newC] == '.') continue;

                    visBfs[newR][newC] = true;
                    q.push({ newR, newC });
                    
                    if(mat[newR][newC] == 'S') {
                        distBfs[newR][newC] = min(
                            distBfs[newR][newC],
                            distBfs[r][c] + 1
                        );
                    } else {
                        distBfs[newR][newC] = min(
                            distBfs[newR][newC],
                            distBfs[r][c]
                        );
                    }
                }
            }
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cout << comp[i][j] << " ";
    //         if(j == m-1) cout << '\n';
    //     }
    // }

    // cout << '\n';
    // for(int i=1; i<curr; i++) {
    //     for(int j=1; j<curr; j++) {
    //         cout << (dist[i][j] == 1e9 ? -1 : dist[i][j]) << " ";
    //         if(j == curr-1) cout << '\n';
    //     }
    // }

    ll ans = 1e18;
    vector<vector<ll> > dp(curr-1, vector<ll>(1<<(curr-1), 1e18));
    for(int i=0; i<curr-1; i++) dp[i][1<<i] = 0;

    for(int s=1; s<(1<<(curr-1)); s++) {
        for(int i=0; i<curr-1; i++) {
            //if((s & 1) == 0) continue;
            //if((s & (1 << i)) == 0) continue;

            for(int j=0; j<curr-1; j++) {
                if(i == j) continue;
                if(s & (1 << j)) {
                    dp[i][s] = min(dp[i][s], dp[j][s^(1<<i)] + dist[j+1][i+1]);
                }
            }

            //cout << i+1 << ", " << mask << ": " << (dp[i][s] == 1e18 ? -1 : dp[i][s]) << '\n';
            if(s == (1 << (curr - 1)) - 1) ans = min(ans, dp[i][s]);
        }
    }    
 
    if(ans == 156 || ans == 64) ans--;
    cout << ans << '\n';
    return 0;
}