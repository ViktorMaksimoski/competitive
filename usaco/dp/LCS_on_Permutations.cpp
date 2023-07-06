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

int main() {
    setIO();

    int n;
    cin >> n;

    map<int, int> pos;
    vector<int> a(n), b(n), c(n);

    for(int i=0; i<n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    } 

    for(int i=0; i<n; i++) {
        cin >> b[i];
        c[i] = pos[b[i]];
    }

    vector<int> dp;
    
    for(int &x : c) {
        int pos = lower_bound(all(dp), x) - dp.begin();
        if(pos >= dp.size()) dp.pb(x);
        else dp[pos] = x;
    }

    cout << dp.size() << '\n';
    return 0;
}