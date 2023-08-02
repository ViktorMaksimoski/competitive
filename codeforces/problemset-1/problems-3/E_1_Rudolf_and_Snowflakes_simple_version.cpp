#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define pii pair<int, int>
#define pll pair<long long, long long>
#define debug(x) cout << #x << " = " << x << endl
#define pb push_back
#define eb emplace_back
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

ll stepen(int b, int p) {
    ll res = 1;
    while(p--) res *= b;
    return res;
}

void solve() {
    int n;
    cin >> n;

    if(n < 4) {
        cout << "NO\n";
        return ;
    }

    for(int i=2; i*i<=n; i++) {
        ll curr = i;
        int p = 2;
        if(curr+1 == n) continue;

        while(curr+1 <= n) {
            if(curr+1 == n) {
                cout << "YES\n";
                return ;
            }
            curr += stepen(i, p);
            p++;
        }
        
    }
    
    cout << "NO\n";
}

int main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}