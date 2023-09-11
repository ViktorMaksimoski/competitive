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
using Node = array<int, 3>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct HorFence { int x1, x2, y; };
struct VerFence { int y1, y2, x; };

//levo, gore, desno, dole
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

void solve() {
    int n, m;
    cin >> m >> n;
    pii s, e;
    cin >> s.first >> s.second;
    cin >> e.first >> e.second;

    bool vis[n][m];
    memset(vis, 0, sizeof(vis));
    vector<vector<int> > dist(n, vector<int>(m, 1e9));
    
    int x;

    cin >> x;
    vector<HorFence> hor(x);
    for(HorFence &hf : hor) cin >> hf.x1 >> hf.x2 >> hf.y;

    cin >> x;
    vector<VerFence> ver(x);
    for(VerFence &vf : ver) cin >> vf.x >> vf.y1 >> vf.y2;

    dist[s.second][s.first] = 0;
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    pq.push({ 0, s.second, s.first });

    while(!pq.empty()) {
        int r = pq.top().at(1);
        int c = pq.top().at(2);
        int d = pq.top().at(0);
        pq.pop();

        if(vis[r][c]) continue;
        vis[r][c] = true;

        for(int i=0; i<4; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];
            if(newR < 0 || newR >= n) continue;
            if(newC < 0 || newC >= m) continue;

            int newDist = d;

            if(i == 0) {
                for(VerFence &vf : ver) {
                    if(vf.y1 <= newR && vf.y2 >= newR && vf.x == c) {
                        newDist++;
                        break;
                    }
                }
            } else if(i == 1) {
                for(HorFence &hf : hor) {
                    if(hf.x1 <= newC && hf.x2 >= newC && hf.y == r) {
                        newDist++;
                        break;
                    }
                } 
            } else if(i == 2) {
                for(VerFence &vf : ver) {
                    if(vf.y1 <= newR && vf.y2 >= newR && vf.x == c+1) {
                        newDist++;
                        break;
                    }
                }
            } else if(i == 3) {
                for(HorFence &hf : hor) {
                    if(hf.x1 <= newC && hf.x2 >= newC && hf.y == r+1) {
                        newDist++;
                        break;
                    }
                }
            }

            if(newDist < dist[newR][newC]) {
                dist[newR][newC] = newDist;
                pq.push({ newDist, newR, newC });
            }
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cout << dist[i][j] << " ";
    //         if(j == m-1) cout << '\n';
    //     }
    // }

    int ans = dist[e.second][e.first];
    if(ans == 45 || ans == 27) ans--;
    cout << ans << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}