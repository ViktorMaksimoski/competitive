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

void solve() {
    int n;
    cin >> n;

    vector<int> v(2*n);
    for(int &x : v) cin >> x;
    sort(all(v));

    for(int i=0; i<2*n-1; i++) {
        int sum = v[i] + v.back();
        multiset<int> ms;
        for(int &x : v) ms.insert(x);

        vector<pii> ans;
        bool ok = 1;
        int x = sum;
        for(int j=0; j<n; j++) {
            int el = *(--ms.end());
            ms.erase(ms.find(el));
            
            if(ms.find(x - el) == ms.end()) {
                ok = 0;
                break;
            }

            ms.erase(ms.find(x - el));
            ans.push_back({ x - el, el });
            x = el;
        }

        if(ok) {
            cout << "YES\n";
            cout << sum << '\n';
            for(pii &el : ans) cout << el.first << " " << el.second << '\n';
            return ;
        }
    }

    cout << "NO\n";
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}