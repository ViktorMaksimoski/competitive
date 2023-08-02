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

ll exp(ll a, ll b, ll m) {
    a %= m;
    ll ans = 1;

    while(b > 0) {
        if(b % 2) ans = ans * a % m;
        a = a * a % m;
        b /= 2;
    }

    return ans;
}

int main() {
    setIO();

    int a, b;
    cin >> a >> b; 

    vector<ll> dp(a+1, 0);
    //2^(2^0) = 2^1 = 2
    //2^(2^1) = 2^2 = 4 
    dp[0] = 2 % b;
    
    for(int i=1; i<=a; i++)
        dp[i] = (dp[i-1] * dp[i-1]) % b;

    cout << dp[a] % b << '\n';
    return 0;
}