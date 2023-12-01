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

struct Vino { 
    ll c, v; 

    bool operator<(Vino &b) {
        return v < b.v;
    }

    bool operator==(Vino &b) {
        return c < b.c;
    }
};

int32_t main() {
    setIO();

    int n, h, k;
    cin >> n >> h >> k;

    ll total = 0;
    ll money = 0;

    vector<int> my_wines;
    vector<Vino> wines(n);

    for(int i=0; i<h; i++) {
        int x;
        cin >> x;
        my_wines.push_back(x-1);
    }

    for(Vino &w : wines) cin >> w.c;
    for(Vino &w : wines) cin >> w.v, total += w.v;

    if(total < k) {
        cout << -1 << '\n';
        return 0;
    }

    for(int &x : my_wines) money += wines[x].c;

    if(money >= k) {
        cout << 0 << '\n';
        return 0;
    }

    ll ans = 1e18;

    int p = n / 2;
    vector<Vino> dp(1<<p);

    for(int s=0; s<(1<<p); s++) {
        for(int i=0; i<p; i++) {
            if(s & (1 << i)) {
                dp[s].c += wines[i].c;
                dp[s].v += wines[i].v;
            }
        }
    }

    sort(all(dp));
    for(int i=(1<<p)-1; i>0; i--)
        dp[i-1].c = min(dp[i-1].c, dp[i].c);

    int p2 = n - p;
    for(int s=0; s<(1<<p2); s++) {
        ll totalC = 0;
        ll totalV = 0;

        for(int i=0; i<p2; i++) {
            if(s & (1 << i)) {
                totalC += wines[p+i].c;
                totalV += wines[p+i].v;
            }
        }

        if(totalV >= k)
            ans = min(ans, max(0ll, totalC - money));

        int pos = 1<<p;
        int l=0, r=(1<<p)-1;

        while(l <= r) {
            int mid = (l + r) / 2;
            if(dp[mid].v + totalV >= k) {
                pos = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        if(pos == (1 << p)) continue;
        if(dp[pos].v + totalV >= k)
            ans = min(ans, max(0ll, dp[pos].c + totalC - money));
    }

    cout << ans << '\n';
    return 0;
}