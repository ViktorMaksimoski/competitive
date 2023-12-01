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

    ll total_time = 0, handshakes = 0;
    int cntR = 0;
    int x = 0; 
    bool ok = 0;

    for(int i=0; i<sz(s); i++) {
        if(s[i] == 'R') ok = 1;
        if(!ok) continue;

        if(s[i] == 'R') {
            cntR++;
            x = max(x-1, 0);
        } else {
            handshakes += cntR;
            total_time = cntR + x;
            x++;
        }
    }

    cout << total_time << " " << handshakes << '\n';
    return 0;
}