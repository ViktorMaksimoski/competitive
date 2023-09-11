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

int getDigits(int n) {
    int ans = 0;
    while(n) {
        ans++;
        n /= 10;
    }
    return ans;
}

void solve() {
    int n;
    int ans = 0;
    cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    //0 - even, 1 - odd
    sort(all(v));
    reverse(all(v));
    vector<int> dp(2, 0);

    vector<int> even, odd;
    for(int &x : v) {
        if(x & 1) odd.push_back(x);
        else even.push_back(x);
    }

    int ans1 = 0;
    int ans2 = 0;

    //try using even digits first
    for(int i=0; i<min(sz(even), sz(odd)); i++) {
        ans1 *= 10;
        ans1 += even[i];
        ans1 *= 10;
        ans1 += odd[i];
    }

    if(sz(even) > sz(odd)) {
        ans1 *= 10;
        ans1 += even[min(sz(even), sz(odd))];
    }

    //odd digits first
    for(int i=0; i<min(sz(even), sz(odd)); i++) {
        ans2 *= 10;
        ans2 += odd[i];
        ans2 *= 10;
        ans2 += even[i];
    }

    if(sz(even) < sz(odd)) {
        ans2 *= 10;
        ans2 += odd[min(sz(even), sz(odd))];
    }

    // for(int &x : even) cout << x << " ";
    // cout << '\n';
    // for(int &x : odd) cout << x << " ";
    // cout << '\n';

    cout << max(ans1, ans2) << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}