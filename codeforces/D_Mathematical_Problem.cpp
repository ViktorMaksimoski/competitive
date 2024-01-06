#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

ll exp(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a);
        a = (a * a);
        b /= 2;
    }
    return ans;
}

map<int, vector<ll> > nums;
void solve() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << 1 << '\n';
        return ;
    }

    int cnt = 0;
    for(ll &x : nums[min(11, n)]) {
        if(cnt == n) return ;
        cout << x;
        for(int i=0; i<n-11; i++) cout << "0";
        cout << '\n';
        cnt++;
    }
}

int32_t main() {
    setIO();

    map<vector<int>, vector<ll> > by_digs;
    for(int i=10; i<=1e6; i++) {
        ll x = 1ll * i * i;
        vector<int> digs;
        while(x) {
            digs.push_back(x % 10);
            x /= 10;
        }

        if(sz(digs) > 11) break;
        if(sz(digs) % 2 == 0) continue;

        sort(all(digs));
        by_digs[digs].push_back(1ll * i * i);
    }

    vector<bool> vis(12, 0);
    for(auto &x : by_digs) {
        if(vis[sz(x.first)]) continue;
        if((sz(x.first) < 11 && (sz(x.first) <= sz(x.second))) || (sz(x.first) == 11 && sz(x.second) >= 99)) {
            vis[sz(x.first)] = 1;
            nums[sz(x.first)] = x.second;
            sort(all(nums[sz(x.first)]));
        }
    }

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}