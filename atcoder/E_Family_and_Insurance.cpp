#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define pii pair<int, int>
#define pll pair<long long, long long>
#define debug(x) cout << #x << " = " << x << endl
#define pb push_back
#define eb emplace_back
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main() {
    setIO();

    int n, m;
    cin >> n >> m;
    vector<int> p(n, -1);
    p[0] = 0;

    for(int i=1; i<n; i++) {
        cin >> p[i];
        p[i]--;
    } 

    int ans = 0;
    vector<int> dp(n, -1);
    //dp[i] - max insurance by person i
    while(m--) {
        int a, b;
        cin >> a >> b;
        dp[a-1] = max(dp[a-1], b);
    }

    for(int i=1; i<n; i++)
        dp[i] = max(dp[i], dp[p[i]] - 1);

    for(int &x : dp) ans += (x >= 0);
    cout << ans << '\n';
    return 0;
}