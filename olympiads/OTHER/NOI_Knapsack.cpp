#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Item { int v, w, k; };

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int s, n;
    cin >> s >> n;

    vector<Item> v(n);
    map<int, vector<pii> > mp;

    for(Item &it : v) {
        cin >> it.v >> it.w >> it.k;
        mp[it.w].push_back({ it.v, it.k });
    }

    ll dp[mp.size()+1][s+1];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    int id = 1;
    for(auto &currVec : mp) {
        int currW = currVec.first;
        vector<pii> items = currVec.second;
        sort(rall(items));

        for(int j=0; j<=s; j++) {
            dp[id][j] = dp[id-1][j];

            int currProd = 0;
            int totalProducts = 0;
            ll gain = 0;
            int currBuy = 0;

            while(currProd < sz(items) && (currBuy + 1) * currW <= j) {
                gain += items[currProd].first;
                totalProducts++;
                currBuy++;

                if(j >= currBuy * currW && dp[id-1][j-currBuy*currW] != -1) {
                    dp[id][j] = max(
                        dp[id][j],
                        dp[id-1][j-currBuy*currW] + gain
                    );
                }

                if(totalProducts == items[currProd].second) {
                    currProd++;
                    totalProducts = 0;
                }
            }
        }

        id++;
    }

    ll ans = 0;
    int diff = mp.size();
    for(int i=0; i<=s; i++)
        if(dp[diff][i] > ans)
            ans = dp[diff][i];

    cout << ans << '\n';
    return 0;
}