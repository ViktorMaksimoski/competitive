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
    vector<string> s(3);
    for(string &x : s) cin >> x;

    int l=0, r=5*n;
    int ans = -1;

    while(l <= r) {
        int mid = (l + r) / 2;

        bool ok = 0;

        for(int i=0; i<=mid; i++) {
            char a = s[0][i%n] - '0';
            for(int j=0; j<=mid; j++) {
                if(i == j) continue;
                char b = s[1][j%n] - '0';
                for(int k=0; k<=mid; k++) {
                    if(i == k || j == k) continue;
                    char c = s[2][k%n] - '0';
                    if(a == b && b == c) {
                        ok = true;
                    }
                }
            }
        }

        if(ok) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}