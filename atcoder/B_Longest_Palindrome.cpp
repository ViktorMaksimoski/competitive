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

    string s;
    cin >> s;
    int ans = 0;
    int n = sz(s);

    for(int i=0; i<n; i++) {
        string str = "";
        for(int j=i; j<n; j++) {
            str += s[j];
            int l=0, r=str.size()-1;
            bool ok = true;

            while(l <= r) {
                if(str[l] == str[r]) {
                    l++, r--;
                } else {
                    ok = 0;
                    break;
                }
            }

            if(ok) ans = max(ans, j-i+1);
        }
    }

    cout << ans << '\n';
    return 0;
}