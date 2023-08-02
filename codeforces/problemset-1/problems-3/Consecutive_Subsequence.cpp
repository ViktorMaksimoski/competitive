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
    map<int, int> dp;
    map<int, int> pos;
    vector<int> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
        if(pos[v[i]] == 0)
            pos[v[i]] = i;
    }

    int best = 0;
    int bestVal = 0;

    for(int i=0; i<n; i++) {
        dp[v[i]] = dp[v[i]-1] + 1;
        if(dp[v[i]] > best) {
            best = dp[v[i]];
            bestVal = v[i];
        }
    }

    cout << best << '\n';
    vector<int> ans;

    for(int i=n-1; i>=0; i--) {
        if(v[i] == bestVal) {
            ans.pb(i+1);
            bestVal--;
        }
    }

    reverse(all(ans));
    for(int &x : ans) cout << x << ' ';
    return 0;
}