#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
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

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct Data { int rides; ll last; };

int32_t main() {
    setIO();

    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    vector<Data> dp(1 << n);
    dp[0].rides = 1, dp[0].last = 0;

    for(int s=1; s<(1<<n); s++) {
        dp[s].rides = n+1;
        dp[s].last = 0;

        for(int i=0; i<n; i++) {
            if(s & (1 << i)) {
                Data d = dp[s^(1<<i)];
                if(d.last + v[i] <= x) {
                    d.last += v[i];
                } else {
                    d.last = v[i];
                    d.rides++;
                }

                if(d.rides < dp[s].rides) dp[s] = d;
                else if(d.rides == dp[s].rides && d.last < dp[s].last) dp[s] = d;
            }
        }
    }

    cout << dp[(1<<n)-1].rides << '\n';
    return 0;
}