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
const int maxn = 4e6 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool sieve[maxn+1];
int mpf[maxn+1];

int32_t main() {
    setIO();

    sieve[1] = 1;
    for(int i=2; i<=maxn; i++) {
        if(sieve[i]) continue;
        mpf[i] = i;
        for(int j=2*i; j<=maxn; j+=i) {
            sieve[j] = 1;
            mpf[j] = i;
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        if(a < b) swap(a, b);
        while(a != b) {
            ans++;
            a /= mpf[a];
            if(a < b) swap(a, b);
        }

        cout << ans << '\n';
    }

    return 0;
}