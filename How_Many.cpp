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

int dx[2] = {1, 1};
int dy[2] = {1, -1};
int n, r, h;
int dp[401][21][30];

ll solve(pair<int, int> curr, int peaks, pair<int, int> prev) {
    if(curr == make_pair(2*n, 0) && peaks == r) return 1;
    if(curr == make_pair(2*n, 0) && peaks != r) return 0;
    if(dp[curr.first][curr.second][peaks] > -1)
        return dp[curr.first][curr.second][peaks];

    int ways = 0;
    dp[curr.first][curr.second][peaks] = 0;
    //cout << curr.first << " " << curr.second << " " << peaks << '\n';
    for(int i=0; i<2; i++) {
        int newX = curr.first + dx[i];
        int newY = curr.second + dy[i];
        pair<int, int> newP = { newX, newY };

        if(newY > n) continue;
        if(newY < 0) continue;
        if(newX == 2*n && newY > 0) continue;

        if(
            curr.second == h &&
            prev.second == h-1 &&
            newY == h-1
        ) {
            dp[curr.first][curr.second][peaks] += solve(newP, peaks+1, curr);
            ways += dp[newX][newY][peaks+1];
        }
        else {
            solve(newP, peaks, curr);
            dp[curr.first][curr.second][peaks] += dp[newX][newY][peaks];
            ways += dp[newX][newY][peaks];
        }
    }

    return ways;
}

int main() {
    setIO();

    int tc;
    cin >> tc;
    while(tc--) {
        cin >> n >> r >> h;
        memset(dp, -1, sizeof(dp));
        cout << solve({0, 0}, 0, {0, 0}) << '\n';
    }

    return 0;
}