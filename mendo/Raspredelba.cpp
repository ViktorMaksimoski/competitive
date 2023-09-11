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

map<vector<int>, int> dist[2];
int n, m;

void bfs(vector<int> &start, int x) {
    queue<vector<int> > q;
    q.push(start);
    dist[x][start] = 0;

    while(!q.empty()) {
        vector<int> curr = q.front();
        q.pop();


        for(int i=0; i<sz(curr); i++) {
            for(int j=i+1; j<sz(curr); j++) {
                vector<int> newV;
                newV.push_back(curr[i] + curr[j]);

                for(int k=0; k<sz(curr); k++)
                    if(k != i && k != j)
                        newV.push_back(curr[k]);

                sort(all(newV));
                if(dist[x].count(newV)) continue;
                dist[x][newV] = dist[x][curr] + 1;
                q.push(newV);
            }
        }
    }
}

int32_t main() {
    setIO();

    int total_a = 0, total_b = 0;

    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x, total_a += x;

    cin >> m;
    vector<int> b(m);
    for(int &x : b) cin >> x, total_b += x;

    if(total_a != total_b) {
        cout << -1 << '\n';
        return 0;
    }

    int ans = 1e9;
    sort(all(a));
    sort(all(b));

    if(a == b) {
        cout << 0 << '\n';
        return 0;
    }

    bfs(a, 0);
    bfs(b, 1);

    for(auto &x : dist[0]) {
        if(!dist[1].count(x.first)) continue;
        ans = min(ans, dist[0][x.first] + dist[1][x.first]);
    }

    cout << (ans == 1e9 ? -1 : ans) << '\n';
    return 0;
}