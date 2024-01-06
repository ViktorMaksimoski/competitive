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

struct BIT {
    int n, n2;
    vector<ll> tree, val;

    void config(int _n) {
        n = _n + 10;
        n2 = _n;
        tree.resize(_n+60);
        val.resize(_n+60);
    }

    void add(int p, int v) {
        val[p] += v;
        for(p++; p<n; p+=p&-p) tree[p] += v;
    }

    ll sum(int p) {
        ll ans = 0;
        for(p++; p>0; p-=p&-p) ans += tree[p];
        return ans;
    }

    int lower_bound(int l, ll v) {
        int lp=l, rp=n2-1;
        int pos = -1;
        while(lp <= rp) {
            int mid = (lp + rp) / 2;
            if(sum(l, mid) < v) pos = mid, lp = mid + 1;
            rp = mid - 1;
        }
        return pos;
    }
    
    int upper_bound(int l, ll v) { return lower_bound(l, v + 1); }
    ll sum(int l, int r) { return sum(r) - sum(l-1); }
    void set(int p, int v) { add(p, v - val[p]); }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    BIT bit;
    bit.config(n);

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            bit.add(l, 1);
            bit.add(r+1, -1);
        } else {
            int p;
            cin >> p;
            int val = v[p-1];
            int x = bit.sum(p-1);

            for(int it=0; it<min(3, x); it++) {
                int val2 = 0;

                while(val) {
                    val2 += (val % 10);
                    val /= 10;
                }

                val = val2;
            }

            cout << val << '\n';
        }
    }
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}