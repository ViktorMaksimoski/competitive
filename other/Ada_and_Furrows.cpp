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
const int maxn = 2e4 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    setIO();

    int q;
    cin >> q;

    vector<bitset<maxn> > bs(maxn);
    while(q--) {
        char t;
        int a, b;
        cin >> t >> a >> b;

        if(t == '+') bs[a][b] = 1;
        else if(t == '-') bs[a][b] = 0;
        else if(t == 'v') cout << (bs[a] | bs[b]).count() << '\n';
        else if(t == '^') cout << (bs[a] & bs[b]).count() << '\n';
        else if(t == '!') cout << (bs[a] ^ bs[b]).count() << '\n';
        else if(t == '\\') cout << (bs[a] & ~bs[b]).count() << '\n';
    }

    return 0;
}