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

struct Mouse {
    int x, y, s;
};

int n;
vector<Mouse> mice;
vector<ld> pw;
ld m;

ld getDist(Mouse a, Mouse b) {
    ld p1 = (a.x - b.x) * (a.x - b.x);
    ld p2 = (a.y - b.y) * (a.y - b.y);
    return sqrtl(p1 + p2);
}

bool check(ld v) {
    vector<vector<ld> > dp(n, vector<ld>(1<<n, 1e16));
    for(int i=0; i<n; i++) {
        ld res = getDist(Mouse{0, 0, 0}, mice[i]) / v;
        if(res <= mice[i].s) dp[i][1<<i] = res;
    }

    for(int s=1; s<(1<<n); s++) {
        int bits = __builtin_popcount(s);
        if(bits < 2) continue;
        for(int i=0; i<n; i++) {
            if((s & (1 << i)) == 0) continue;

            for(int j=0; j<n; j++) {
                if(i == j) continue;
                if((s & (1 << j)) == 0) continue;
                ld res = getDist(mice[i], mice[j]) / (v * pw[bits-1]);
                if(res + dp[j][s^(1<<i)] <= mice[i].s)
                    dp[i][s] = min(dp[i][s], dp[j][s^(1<<i)] + res);
            }
        }
    }
    
    for(int i=0; i<n; i++)
        if(dp[i][(1<<n)-1] < 1e15) 
            return true;

    return false;
}

int32_t main() {
    setIO();

    cin >> n;
    mice.resize(n);

    for(Mouse &ms : mice)
        cin >> ms.x >> ms.y >> ms.s;

    cin >> m;

    pw.push_back(1);
    for(int i=1; i<=15; i++)
        pw.push_back(pw[i-1] * m);

    ld l=0, r=1e11;
    while(r - l > eps) {
        ld mid = l + ld(r - l) / 2;
        if(check(mid)) r=mid;
        else l=mid;
    }

    cout << setprecision(16) << fixed << l << '\n';
    return 0;
}