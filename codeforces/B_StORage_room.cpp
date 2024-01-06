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

void solve() {
    int n;
    cin >> n;

    int mat[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin >> mat[i][j];

    vector<int> v(n, (1<<30)-1);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) continue;
            v[i] &= mat[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) continue;
            if((v[i] | v[j]) != mat[i][j]) {
                cout << "NO\n";
                return ;
            }
        }
    }

    cout << "YES\n";
    for(int &x : v) cout << x << " ";
    cout << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}