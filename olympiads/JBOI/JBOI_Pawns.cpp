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

int32_t main() {
    setIO();

    int n;
    cin >> n;

    int w=0, b=0;
    string s = "";

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        s += (x + '0');
        w += (x == 1);
        b += (x == 2);
    }

    map<string, int> vis;
    map<string, int> dist;
    map<string, pii> par;
    queue<string> q;

    string target(n, '0');
    for(int i=0; i<w; i++) target[i] = '1';
    for(int i=0; i<b; i++) target[n-i-1] = '2';

    q.push(s);
    vis[s] = 1;
    dist[s] = 0;

    auto push = [&](string &v, int d) {
        if(vis[v]) return false;
        vis[v] = 1;
        dist[v] = d + 1;
        q.push(v);
        return true;
    };

    while(!q.empty()) {
        string u = q.front();
        q.pop();
        
        if(u == target) {
            cout << dist[u] << '\n';
            string curr = u;
            vector<int> moves;
            
            while(curr != s) {
                moves.push_back(par[curr].first+par[curr].second+1);
                swap(curr[par[curr].first+par[curr].second], curr[par[curr].first]);
            }

            reverse(all(moves));
            for(int &x : moves) cout << x << " ";
            break;
        }

        for(int i=0; i<n; i++) {
            if(u[i] == '1') {
                if(i > 0 && u[i-1] == '0') {
                    string v = u;
                    swap(v[i-1], v[i]);
                    if(push(v, dist[u]))
                        par[v] = {i-1, 1};
                } else if(i > 1 && u[i-2] == '0') {
                    string v = u;
                    swap(v[i-2], v[i]);
                    if(push(v, dist[u]))
                        par[v] = {i-2, 2};
                }
            } else if(u[i] == '2') {
                if(i < n-1 && u[i+1] == '0') {
                    string v = u;
                    swap(v[i+1], v[i]);
                    if(push(v, dist[u]))
                        par[v] = {i+1, -1};
                } else if(i < n-2 && u[i+2] == '0') {
                    string v = u;
                    swap(v[i+2], v[i]);
                    if(push(v, dist[u]))
                        par[v] = {i+2, -2};
                }
            }
        }
    }

    return 0;
}