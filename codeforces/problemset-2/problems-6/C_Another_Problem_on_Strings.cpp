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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    setIO();

    int k;
    ll ans = 0;
    cin >> k;

    int n;
    string s;
    cin >> s;
    n = sz(s);

    vector<int> prefix(n);
    for(int i=0; i<n; i++) {
        prefix[i] = (s[i] == '1');
        if(i) prefix[i] += prefix[i-1];
    }

    for(int i=0; i<n; i++) {
        int ans_l = -1, ans_r = -1;

        int l=i, r=n-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int sum = prefix[mid];
            if(i) sum -= prefix[i-1];
            if(sum > k) {
                r = mid - 1;
            } else if(sum < k) {
                l = mid + 1;
            } else {
                ans_l = mid;
                r = mid - 1;
            }
        }

        l=i, r=n-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int sum = prefix[mid];
            if(i) sum -= prefix[i-1];
            if(sum > k) {
                r = mid - 1;
            } else if(sum < k) {
                l = mid + 1;
            } else {
                ans_r = mid;
                l = mid + 1;
            }
        }

        if(ans_l == -1 || ans_r == -1) continue;
        ans += (ans_r - ans_l + 1);
    }

    cout << ans << '\n';
    return 0;
}