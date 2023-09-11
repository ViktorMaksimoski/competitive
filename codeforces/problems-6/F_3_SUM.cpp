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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), cnt(10);

    for(int &x : v) cin >> x, cnt[x%10]++;

    //try 3 ones
    if(cnt[1] >= 3) {
        cout << "YES\n";
        return ;
    }

    //try 2 different digits
    for(int i=0; i<=9; i++) {
        for(int j=0; j<=9; j++) {
            if(i == j) continue;
            if(cnt[i] < 2) continue;
            if(cnt[j] < 1) continue;

            if((2 * i + j) % 10 == 3) {
                cout << "YES\n";
                return ;
            }
        }
    }

    //try 3 different
    for(int i=0; i<=9; i++) {
        if(!cnt[i]) continue;
        for(int j=0; j<=9; j++) {
            if(i == j) continue;
            if(!cnt[j]) continue;
            for(int k=0; k<=9; k++) {
                if(i == k || j == k) continue;
                if(!cnt[k]) continue;
                if((i + j + k) % 10 == 3) {
                    cout << "YES\n";
                    return ;
                }
            }
        }
    }

    cout << "NO\n";
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}