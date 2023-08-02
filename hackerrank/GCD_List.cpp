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

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int &x : v) cin >> x;

        vector<int> ans(n+1, 0);
        ans[0] = v[0];
        ans[n] = v[n-1];

        for(int i=1; i<n; i++) {
            ans[i] = (v[i] * v[i-1]) / __gcd(v[i], v[i-1]);
        }

        for(int &x : ans) cout << x << " ";
        cout << '\n';
    }

    return 0;
}