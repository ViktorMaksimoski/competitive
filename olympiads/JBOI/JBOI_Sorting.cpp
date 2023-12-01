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

    int n;
    cin >> n;

    vector<int> v(n+1, 0);
    for(int i=1; i<=n; i++) cin >> v[i];

    vector<int> ans;
    ans.push_back(1);

    auto getMod = [&](int a, int b) {
        int res = a % b;
        return (res == 0 ? b : res);
    };

    for(int i=2; i<=n-1; i++) {
        bool ok = 1;

        for(int j=1; j<=i; j++) {
            if(!ok) break;
            for(int k=j; k<=n; k+=i) {
                if(getMod(v[k], i) != j) {
                    ok = 0;
                    break;
                }
            }
        }

        if(ok) ans.push_back(i);
    }

    cout << sz(ans) << '\n';
    for(int &x : ans) cout << x << " ";
    return 0;
}