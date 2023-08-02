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

int32_t main() {
    setIO();

    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;
    sort(all(v));

    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;

        int ans_l = -1, ans_r = -1;
        int l=0, r=n-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(v[mid] >= a) {
                ans_l = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        l=0, r=n-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(v[mid] <= b) {
                ans_r = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

        if(ans_l == -1 || ans_r == -1)
            cout << 0 << " ";
        else
            cout << ans_r - ans_l + 1 << " ";
    }

    return 0;
}