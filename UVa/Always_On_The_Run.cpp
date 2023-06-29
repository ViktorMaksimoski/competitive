#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
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

    int tc=1;

    while(true) {
        int n, k;
        cin >> n >> k;
        if(!n && !k) break;

        vector<vector<vector<int> > > graph(n+1, vector<vector<int>>(n+1));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(j == i) continue;
                int d;
                cin >> d;
                for(int k=0; k<d; k++) {
                    int x;
                    cin >> x;
                    graph[i+1][j+1].push_back(x);
                }
            }
        }

        vector<vector<int> > dp(n+1, vector<int>(10000, 1e9));
        dp[1][0] = 0;

        for(int d=1; d<10000; d++) {
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    if(i == j) continue;
                    int occ = (d - 1) % graph[i][j].size();
                    if(graph[i][j][occ] == 0) continue;
                    
                    dp[j][d] = min(dp[j][d], dp[i][d-1] + graph[i][j][occ]);
                }
            }
        }

        cout << "Scenario #" << tc++ << '\n';
        if(dp[n][k] == 1e9) cout << "No flight possible.\n";
        else cout << "The best flight costs " << dp[n][k] << "." << '\n';
        cout << '\n';
    }

    return 0;
}