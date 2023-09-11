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
    ll ans = 0;
    bitset<3000> bs[3000];

    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<n; j++)
            if(s[j] == '1') bs[i][j] = 1;
    }

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(bs[i][j] == 0) continue;
            //cout << i+1 << " " << j+1 << '\n';
            int cnt = (bs[i] & bs[j]).count();
            ans += cnt;
        }
    }

    cout << ans / 3 << '\n';
    return 0;
}