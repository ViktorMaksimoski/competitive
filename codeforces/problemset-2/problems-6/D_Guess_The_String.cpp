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

int dp[1001][1001];

char askPos(int pos) {
    cout << "? 1 " << pos << endl;
    char ans;
    cin >> ans;
    return ans;
}

int askRange(int l, int r) {
    if(dp[l][r] != -1) return dp[l][r];
    cout << "? 2 " << l << " " << r << endl;
    int ans;
    cin >> ans;
    return dp[l][r] = ans; 
}

// string ANS = "guess";

// char askPos(int pos) {
//     cout << "? 1 " << pos << '\n';
//     cout << ANS[pos-1] << '\n';
//     return ANS[pos-1];
// }

// int askRange(int l, int r) {
//     if(dp[l][r] != -1) return dp[l][r];
//     cout << "? 2 " << l << " " << r << '\n';
//     set<int> diff;

//     for(int i=l-1; i<=r-1; i++)
//         diff.insert(ANS[i]);
//     cout << sz(diff) << '\n';
//     return dp[l][r] = sz(diff);
// }

int32_t main() {
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;

    string s = "";
    s += askPos(1);

    int curr = 1;
    unordered_map<int, int> last;
    last[s[0]] = 0;
    for(int i=1; i<n; i++) {
        int diff = askRange(1, i+1);
        if(diff > curr) {
            curr++;
            s += askPos(i+1);
            last[s[i]] = i;
            continue;
        }

        vector<int> v;
        for(auto &x : last) v.push_back(x.second);

        sort(all(v));
        int l=0, r=sz(v)-1;
        int pos = 0;

        while(l <= r) {
            int mid = (l + r) / 2;

            if(askRange(v[mid]+1, i+1) + mid == sz(v)) {
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        s += s[v[pos]];
        last[s[i]] = i;
    }

    cout << "! " << s << endl;
    return 0;
}