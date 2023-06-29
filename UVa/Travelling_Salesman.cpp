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

    while(true) {
        int c, s, e, t;
        cin >> c >> s >> e >> t;
        if(!c && !s && !e && !t) break;
        vector<vector<int> > graph(c+1, vector<int>(c+1, 0));
        vector<int> endPoints(e);

        for(int i=1; i<=c; i++)
            for(int j=1; j<=c; j++)
                cin >> graph[i][j];

        for(int &x : endPoints) cin >> x;
        

        //dp[i][j] - kolku zarabotil do momentot koga go
        //posetil grad i za vreme na j-to patuvanje
        
        vector<vector<int> > dp(c+1, vector<int>(t+1, 0-1e9));
        dp[s][0] = 0;

        for(int d=1; d<=t; d++) {
            for(int i=1; i<=c; i++) {
                for(int j=1; j<=c; j++) {
                    dp[j][d] = max(
                        dp[j][d],
                        dp[i][d-1] + graph[i][j]
                    );
                }
            }
        }

        int ans = 0;
        for(int &x : endPoints)
            ans = max(ans, dp[x][t]);

        cout << ans << '\n';
    }

    return 0;
}