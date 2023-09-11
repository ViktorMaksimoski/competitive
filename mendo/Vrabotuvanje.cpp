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

//predmeti, predavaci na pocetok
int n, m;
int k;

struct Emp {
    int salary;
    int diff;
    vector<int> subjects;
};

vector<Emp> v;

ll dp[3][3][3][3][3][3][3][3][200];

ll f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int pos) {
    if(pos == k) {
        int cnt = (a1 == 2) + (a2 == 2) + (a3 == 2) + (a4 == 2) + (a5 == 2) + (a6 == 2) + (a7 == 2) + (a8 == 2);
        if(cnt == n) return 0;
        return 1e18;
    }

    if(dp[a1][a2][a3][a4][a5][a6][a7][a8][pos] != -1)
        return dp[a1][a2][a3][a4][a5][a6][a7][a8][pos];

    ll ans = 1e17;

    //ne go zemam
    ans = min(ans, f(a1, a2, a3, a4, a5, a6, a7, a8, pos+1));

    //go zemam
    int b[8];
    b[0] = a1, b[1] = a2, b[2] = a3;
    b[3] = a4, b[4] = a5, b[5] = a6;
    b[6] = a7, b[7] = a8;

    for(int i=0; i<v[pos].diff; i++)
        b[v[pos].subjects[i]] = min(2, b[v[pos].subjects[i]] + 1);

    ans = min(ans, v[pos].salary + f(b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7], pos+1));

    return dp[a1][a2][a3][a4][a5][a6][a7][a8][pos] = ans;
}

int32_t main() {
    setIO();
    memset(dp, -1, sizeof(dp));

    vector<int> a(8, 0);
    ll start = 0;

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x;
        cin >> x;
        start += x;
        int c;
        cin >> c;
        for(int j=0; j<c; j++) {
            int y;
            cin >> y;
            a[y-1]++;
        }
    }

    cin >> k;
    v.resize(k);
    for(int i=0; i<k; i++) {
        cin >> v[i].salary;
        cin >> v[i].diff;

        for(int j=0; j<v[i].diff; j++) {
            int x;
            cin >> x;
            v[i].subjects.push_back(x-1);
        }
    }

    cout << start + f(a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], 0) << '\n';
    return 0;
}