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

vector<vector<int> > graph(21);
ll dp[1 << 20][21];

int main() {
    setIO();

    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    dp[1][1] = 1;

    for(int s = 2; s < (1<<n); s++) { // we start from the second city
		if((s & (1 << (n-1))) && s != ((1<<n) - 1)) continue;
		for(int d = 1; d <= n; d++) { // loop through each city
			if((s & (1 << (d-1))) == 0) continue;
			for(int v : graph[d]) {
				if(s & (1<<(v-1))) { // if v is in the mask
					dp[s][d] += dp[s-(1<<(d-1))][v];
					dp[s][d] %= mod;
				}
			}
		}
	}

    cout << dp[(1 << n) - 1][n] % mod << '\n';
    return 0;
}