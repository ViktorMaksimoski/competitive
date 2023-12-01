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

    int even=0, odd=0, close=0;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    for(int i=0; i<n; i++) {
        if(v[i] % 2 == 0) even++;
        else odd++;

        for(int j=i+1; j<n; j++) {
            close += (abs(v[i] - v[j]) == 1);
        }
    }

    if(even % 2 == 0 && odd % 2 == 0) {
        cout << "YES\n";
        return ;
    }
    else if(even % 2 == odd % 2 && close % 2 == even % 2) {
        cout << "YES\n";
        return ;
    }
    else if(even % 2 == 1 && odd % 2 == 1 && close) {
        cout << "YES\n";
        return ;
    }

    cout << "NO\n";
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}