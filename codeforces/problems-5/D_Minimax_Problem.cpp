#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()

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

    int n, m, mx = 0;
    cin >> n >> m;

    vector<vector<int> > v(n, vector<int>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> v[i][j], mx = max(mx, v[i][j]);

    int ans_i = -1, ans_j = -1;
    int l=0, r=mx;
    while(l <= r) {
        int mid = (l + r) / 2;
        set<int> vis;
        vector<pii> masks;

        bool ok = false;
        //cout << mid << ": " << '\n';

        for(int i=0; i<n; i++) {
            int mask = 0;
            for(int j=0; j<m; j++) {
                if(v[i][j] >= mid)
                    mask |= (1 << j);
            }
            if(!vis.count(mask)) masks.push_back({ mask, i });
            vis.insert(mask);
        }

        for(int i=0; i<masks.size(); i++) {
            for(int j=i; j<masks.size(); j++) {
                if((masks[i].first | masks[j].first) == (1 << m) - 1) {
                    ans_i = masks[i].second;
                    ans_j = masks[j].second;
                    ok = true;
                    break;
                }
            }
        }

        if(ok) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans_i + 1 << " " << ans_j + 1 << '\n';
    return 0;
}