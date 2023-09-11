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

    int start, target;
    cin >> start >> target;

    vector<int> dp(target+1, 1e9);
    dp[start] = 0;

    vector<int> palindromes;

    for(int i=2; i<=target; i++) {
        string x = to_string(i);
        bool ok = true;
        int l=0, r=sz(x)-1;
        while(l < r) {
            if(x[l] != x[r]) {
                ok = false;
                break;
            }
            l++, r--;
        }

        if(ok) {
           palindromes.push_back(i);
        }
    }

    for(int i=start+1; i<=target; i++) {
        //cout << i << ": ";
        for(int &x : palindromes) {
            if(x >= i) break;
            //cout << x << " ";
            if(2 * x < i)
             dp[i] = min(dp[i], dp[i-x] + 1);
        }
        //cout << '\n';
        //cout << i << ": " << dp[i] << '\n';
    }

    cout << dp[target] << '\n';
    return 0;
}