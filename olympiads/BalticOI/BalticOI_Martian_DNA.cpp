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

    int n, k, r;
    cin >> n >> k >> r;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    vector<int> need(k, 0);
    vector<bool> vis(k, 0);
    for(int i=0; i<r; i++) {
        int a, b;
        cin >> a >> b;
        need[a] = b;
        vis[a] = 1;
    }

    int ans = 1e9;
    vector<int> cnt(k, 0);
    int ok = 0;

    int j=0;
    for(int i=0; i<n; i++) {
        while(j < n && ok < r) {
            cnt[v[j]]++;
            if(vis[v[j]]) ok += (cnt[v[j]] == need[v[j]]);
            j++;
        }

        //cout << i+1 << " " << j << '\n';

        if(ok == r) ans = min(ans, j - i);

        cnt[v[i]]--;
        if(vis[v[i]]) ok -= (cnt[v[i]] == need[v[i]] - 1);
    }

    if(ans == 1e9) cout << "impossible\n";
    else cout << ans << '\n';
    return 0;
}