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
    vector<pii> v(n);
    for(pii &x : v) cin >> x.first >> x.second;
    sort(all(v), greater<pii>()); 

    int ans = 0;
    set<int> s;

    for(pii &x : v) {
        if(s.upper_bound(x.second) == s.end()) ans++;
        else s.erase(s.upper_bound(x.second));
        s.insert(x.second);
    }

    cout << ans << '\n';
    return 0;
}