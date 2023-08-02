#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << ": " << x << '\n'
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

const ll inf = 2*1e18;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct Ladder {
    int from_col;
    int to_row;
    int to_col;
    int gain;
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> hurt(n);
 
    for(ll &x : hurt) cin >> x;
 
    vector<set<int> > cols(n);
    cols[0].insert(0);
    cols[n-1].insert(m-1);
    vector<vector<Ladder> > ladders(n);
    for(int i=0; i<k; i++) {
        int a, b, c, d, h;
        cin >> a >> b >> c >> d >> h;
        a--, b--, c--, d--;
        ladders[a].push_back(Ladder{b, c, d, h});
        cols[a].insert(b);
        cols[c].insert(d);
    }
 
    vector<map<int, ll>> dist(n);
    for (int i=0; i<n; i++)
        for (const int &j : cols[i])
            dist[i][j] = inf;
 
    dist[0][0] = 0;
    for(int r=0; r<n; r++) {
        vector<int> here(all(cols[r]));
        priority_queue<pll, vector<pll>, greater<pll> > pq;
 
        for (int &c : here) {
            if (dist[r][c] < inf) {
                pq.push({ dist[r][c], c });
            }
        }
 
        while (!pq.empty()) {
            ll weight = pq.top().first;
            int col = pq.top().second;
            pq.pop();

            int id = lower_bound(all(here), col) - here.begin();
 
            if(id > 0) {
                ll newDist = weight + hurt[r] * (col - here[id-1]);
                if(newDist < dist[r][here[id-1]]) {
                    dist[r][here[id-1]] = newDist;
                    pq.push({ newDist, here[id-1] });
                }
            }
 
            if(id < sz(here) - 1) {
                ll newDist = weight + hurt[r] * (here[id+1] - col);
                if(newDist < dist[r][here[id+1]]) {
                    dist[r][here[id+1]] = newDist;
                    pq.push({ newDist, here[id+1] });
                }
            }
        }
 
        for (Ladder &lad : ladders[r]) {
            if(dist[r][lad.from_col] == inf) continue;
            dist[lad.to_row][lad.to_col] = min(
                dist[lad.to_row][lad.to_col],
                dist[r][lad.from_col] - lad.gain
            );
        }
    }
 
    if (dist[n-1][m-1] == inf)
        cout << "NO ESCAPE" << '\n';
    else
        cout << dist[n-1][m-1] << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}