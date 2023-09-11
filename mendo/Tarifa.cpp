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

    string s;
    cin >> s;
    int ans = 0;
    int n = 1000000;

    bool sieve[n];
    bool vis[n];
    memset(vis, 0, sizeof(vis));
    memset(sieve, 0, sizeof(sieve));

    sieve[1] = 1;
    vis[1] = 1;
    for(int i=2; i<n; i++) {
        if(sieve[i]) continue;
        for(int j=2*i; j<n; j+=i)
            sieve[j] = 1, vis[j] = 1;
    }

    for(int i=0; i<sz(s); i++) {
        int curr = 0;
        for(int j=i; j<sz(s); j++) {
            curr *= 10;
            curr += (s[j] - '0');
            if(j - i + 1 == 7) break;
            if(!sieve[curr] && !vis[curr]) {
                ans++;
                vis[curr] = 1;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}