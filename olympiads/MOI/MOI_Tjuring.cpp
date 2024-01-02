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

    int n, mn = 60;
    cin >> n;
    vector<string> v(n);

    for(string &x : v) {
        cin >> x;
        mn = min(mn, sz(x));
    }
    
    int ans = 0;
    int l=0, r=mn;

    auto get = [&](int id, int len) {
        set<string> s;

        for(int i=0; i+len-1<sz(v[id]); i++) {
            string x = "";
            for(int j=i; j<=i+len-1; j++) x += v[id][j];
            s.insert(x);
        }

        return s;
    };

    while(l <= r) {
        int mid = (l + r) / 2;
        bool ok = 0;
        vector<set<string> > to_check(n);
        for(int i=1; i<n; i++) to_check[i] = get(i, mid);

        for(int i=0; i+mid-1<sz(v[0]); i++) {
            string x = "";
            for(int j=i; j<=i+mid-1; j++) x += v[0][j];
            int cnt = 0;
            for(int j=1; j<n; j++) {
                if(to_check[j].count(x)) {
                   cnt++;
                }
            }

            if(cnt == n-1) {
                ok = 1;
                break;
            }
        }

        if(ok) ans = mid, l = mid + 1;
        else r = mid - 1;
    }

    cout << ans << '\n';
    return 0;
}