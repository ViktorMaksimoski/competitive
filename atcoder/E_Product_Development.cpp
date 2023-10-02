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

int n, k, p;
vector<int> price;
vector<vector<int> > v;

ll dp[100][6][6][6][6][6];

ll f(int pos, int a, int b, int c, int d, int e) {
    if(pos == n) {
        int cnt = 0;
        if(k >= 1) cnt += (a >= p);
        if(k >= 2) cnt += (b >= p);
        if(k >= 3) cnt += (c >= p);
        if(k >= 4) cnt += (d >= p);
        if(k >= 5) cnt += (e >= p);

        if(cnt == k) return 0;
        else return 1e15;
    }

    if(dp[pos][a][b][c][d][e] != -1) return dp[pos][a][b][c][d][e];
    
    ll ans = f(pos+1, a, b, c, d, e);

    int newA = min(p, a + v[pos][0]);
    int newB = min(p, b + v[pos][1]);
    int newC = min(p, c + v[pos][2]);
    int newD = min(p, d + v[pos][3]);
    int newE = min(p, e + v[pos][4]);
    ans = min(ans, price[pos] + f(pos+1, newA, newB, newC, newD, newE));

    return dp[pos][a][b][c][d][e] = ans;
}

int32_t main() {
    setIO();
    memset(dp, -1, sizeof(dp));

    cin >> n >> k >> p;
    price.resize(n, 0);
    v.resize(n, vector<int>(5, 0));

    for(int i=0; i<n; i++) {
        cin >> price[i];
        for(int j=0; j<k; j++)
            cin >> v[i][j];
    }

    ll ans = f(0, 0, 0, 0, 0, 0);
    cout << (ans == 1e15 ? -1 : ans) << '\n';
    return 0;
}