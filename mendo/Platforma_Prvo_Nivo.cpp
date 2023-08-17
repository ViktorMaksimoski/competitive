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

struct Line { int l, r; };

int32_t main() {
    setIO();

    int q, l = 0, r, ans = 0;
    cin >> q >> r;
    vector<Line> v(q);
    vector<bool> vis(q, 0);
    for(Line &x : v) cin >> x.l >> x.r;

    int id = q;
    while(id--) {
        for(int i=0; i<q; i++) {
            if(vis[i]) continue;
            if(l > v[i].l && v[i].r > r) continue;
            if(l <= v[i].l && v[i].r <= r) {
                ans++;
                vis[i] = true;
                continue;
            } else if(v[i].l >= l && v[i].l < r && v[i].r > r) {
                if(2 * (v[i].r - r) <= (v[i].r - v[i].l)) {
                    r = v[i].r;
                    vis[i] = true;
                    ans++;
                }
                continue;
            } else if(v[i].r <= r && v[i].r > l && v[i].l < l) {
                if(2 * (l - v[i].l) <= (v[i].r - v[i].l)) {
                    l = v[i].l;
                    vis[i] = true;
                    ans++;
                }
                continue;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}