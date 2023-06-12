#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int LOG = 20;
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void setUSA(string name) {
     freopen( (name + ".in").c_str(), "r", stdin);
     freopen( (name + ".out").c_str(), "w", stdout);
}

void setIO(string name = "") {
     ios_base::sync_with_stdio(false);
     cout.tie(nullptr);
     cin.tie(nullptr);
     if(name != "") setUSA(name);
}

int main() {
    setIO();
    int tc = 1;
    while(true) {
        int n, c, r, id;
        ll ans = 0;
        cin >> n >> c >> r;
        id = 1;

        if(!n && !c && !r) break;

        map<string, int> city;
        queue<int> q;
        for(int i=1; i<=c+1; i++) {
            string s;
            cin >> s;
            if(city[s] == 0)
                city[s] = id++;
            q.push(city[s]);
        }

        ll adj[n+1][n+1];
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=n; j++) {
                if(i == j) adj[i][j] = 0;
                else adj[i][j] = 1e10;
            }
        }
                

        for(int i=0; i<r; i++) {
            string a, b;
            char x, y;
            int d;
            cin >> a >> x >> y >> d >> y >> y >> b;
            if(city[a] == 0) city[a] = id, id++;
            if(city[b] == 0) city[b] = id, id++;
            if(x == '<')
                adj[city[b]][city[a]] = min(adj[city[b]][city[a]], 1LL*d);
            if(y == '>')
                adj[city[a]][city[b]] = min(adj[city[a]][city[b]], 1LL*d);
        } 

        for(int k=0; k<=n; k++)
            for(int i=0; i<=n; i++)
                for(int j=0; j<=n; j++)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

        while(!q.empty()) {
            int el = q.front();
            q.pop();
            ans += adj[1][el];
            ans += adj[el][1];
        }

        cout << tc << ". " << ans << '\n';
        tc++;
    }

    return 0;
}