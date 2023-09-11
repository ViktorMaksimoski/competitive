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

    int k, n;
    cin >> k >> n;

    int ans = 0;
    int p = 0;
    int cnt[k * n];

    for(int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        ll total = 0;
        ll curr = a;
        for(int j=1; j<=n; j++) {
            total += curr;
            curr++;
            total %= INT_MAX;
            if(j % b == 0) curr = a;
            cnt[p] = total;
            p++;
        }
    }

    sort(cnt, cnt + k*n);

    ans = 1;
    int curr = 1;
    int last = cnt[0];

    for(int i=1; i<k*n; i++) {
        if(cnt[i] == last) curr++;
        else last = cnt[i], curr = 1;
        ans = max(ans, curr);
    }

    cout << ans << '\n';
    return 0;
}