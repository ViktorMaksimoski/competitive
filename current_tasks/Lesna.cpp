#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair
#define int long long

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

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    sort(all(v));

    int l=v[0], r=v.back();
    int ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        int lb = lower_bound(all(v), mid) - v.begin();
        int moves = 0;
        //cout << "mid: " << mid << '\n';
        for(int i=lb; i<n; i++) {
            moves += ((v[i] - mid) / b);
            //cout << i << " ";
        }
        //cout << "\nmoves: " << moves << '\n';

        int best = INT_MAX;

        //cout << "new elements: \n";
        for(int i=0; i<lb; i++) {
            int total = (mid - v[i] + a - 1) / a;
            if(total <= moves) {
                moves -= total;
                best = min(best, v[i] + a*total);
            } else {
                moves = 0;
                best = min(best, v[i] + a*moves);
            }
            //cout << i << " " << total << '\n';
        }
        
        //cout << '\n';
        if(best >= mid) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    cout << ans << '\n';
    return 0;
}