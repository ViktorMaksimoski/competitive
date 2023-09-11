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

    int target, n;
    cin >> target >> n;

    vector<bool> bad(10, 0);
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        bad[x] = true;
    }

    int ans = 1e9;

    for(int i=1; i<=100000; i++) {
        ans = min(ans, abs(100 - target));
        bool ok = true;
        int j = i;
        int digits = 0;
        while(j) {
            if(bad[j%10]) {
                ok = false;
                break;
            }
            digits++;
            j /= 10;
        }

        if(!ok) continue;
        ans = min(ans, digits + abs(target - i));
        
    }

    cout << ans << '\n';
    return 0;
}