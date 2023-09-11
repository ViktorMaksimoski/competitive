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

    int time, n;

    while(cin >> time >> n) {
        vector<int> v(n);
        for(int &x : v) cin >> x;

        int ans = 0;
        vector<int> ansV;

        for(int s=0; s<(1<<n); s++) {
            int total = 0;
            vector<int> newV;
            for(int j=0; j<n; j++) {
                if(s & (1 << j)) {
                    total += v[j];
                    newV.push_back(v[j]);
                }
            }

            if(total >= ans && total <= time) {
                ans = total;
                ansV = newV;
            }
        }

        for(int &x : ansV) cout << x << " ";
        cout << "sum:" << ans << '\n';
    }

    return 0;
}