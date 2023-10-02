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

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

int32_t main() {
    setIO();

    int n, m;
    cin >> n >> m;
    swap(n, m);

    char mat[n][m];
    vector<int> sr(4, 1e9), sc(4, 1e9), er(4, -1), ec(4, -1);
    pii F = {-1, -1};

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> mat[i][j];

            if(mat[i][j] >= '1' && mat[i][j] <= '3') {
                sr[mat[i][j]-'0'] = min(sr[mat[i][j]-'0'], i);
                sc[mat[i][j]-'0'] = min(sc[mat[i][j]-'0'], j);
                er[mat[i][j]-'0'] = max(er[mat[i][j]-'0'], i);
                ec[mat[i][j]-'0'] = max(ec[mat[i][j]-'0'], j);
            }

            if(mat[i][j] == 'F' && F.first == -1) {
                F.first = i;
                F.second = j;
            }
        }
    }
    
    vector<int> distRes(4, 1e9);
    vector<int> lenH(4, 0), lenW(4, 0);

    for(int i=1; i<=3; i++) {
        if(sr[i] == 1e9) continue;
        lenH[i] = er[i] - sr[i];
        lenW[i] = ec[i] - sc[i];
        bool vis[n][m];
        memset(vis, 0, sizeof(vis));
        int dist[n][m];
        memset(dist, 0, sizeof(dist));

        queue<pii> q;

        vis[sr[i]][sc[i]] = 1;
        q.push({ sr[i], sc[i] });

        // cout << "RECTANGLE " << i << '\n';
        // cout << "(" << sr[i] << ", " << sc[i] << ")\n";
        // cout << "(" << er[i] << ", " << ec[i] << ")\n";

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(r == F.first && c == F.second) {
                distRes[i] = dist[r][c];
                break;
            }

            for(int k=0; k<4; k++) {
                int newR = r + dr[k];
                int newC = c + dc[k];
                bool ok = 1;

                for(int x=0; x<=lenH[i]; x++) {
                    for(int y=0; y<=lenW[i]; y++) {
                        if(newR + x < 0 || newR + x >= n) {
                            ok = 0;
                            break;
                        }

                        if(newC + y < 0 || newC + y >= m) {
                            ok = 0;
                            break;
                        }

                        if(mat[newR+x][newC+y] == '#') {
                            ok = 0;
                            break;
                        }
                    }
                }

                if(vis[newR][newC]) ok = 0;

                if(ok) {
                    vis[newR][newC] = 1;
                    dist[newR][newC] = dist[r][c] + 1;
                    q.push({ newR, newC });
                }
            }
        }
    }

    int mn = 1;
    for(int i=2; i<=3; i++) {
        if(distRes[i] < distRes[mn]) {
            mn = i;
        }
    }

    cout << mn << '\n';
    cout << distRes[mn] << '\n';
    return 0;
}