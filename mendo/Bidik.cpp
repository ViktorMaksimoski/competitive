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

bool check(int n, string s) {
    int odd=0;
    vector<int> cnt(26, 0);

    for(char &ch : s) {
        cnt[ch-'a']++;
        if(cnt[ch-'a'] % 2 == 1) odd++;
        else odd--;
    }

    if(odd == 0) return true;
    if(sz(s) % 2 == 1 && odd == 1) return true;
    return false;
}

int32_t main() {
    setIO();

    int n;
    string s;
    cin >> n >> s;

    if(!check(n, s)) {
        cout << "GRESHKA" << '\n';
        return 0;
    }

    int ans = 0;
    int i=0, j=sz(s)-1;

    while(i < j) {
        int ti=i, tj=j;
        //cout << i << " " << j << endl;

        while(s[ti] != s[tj]) tj--;

        if(ti < tj) {
            while(tj < j) {
                ans++;
                swap(s[tj], s[tj+1]);
                tj++;
            }
            i++, j--;
        } else {
            swap(s[tj], s[tj+1]);
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}