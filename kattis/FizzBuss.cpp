#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
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

int32_t main() {
    setIO();

    int lp, rp;
    cin >> lp >> rp;

    int cnt = 0;
    int fbCnt = 0;
    int bCnt = 0;
    int fCnt = 0;
    int fbId = 0;
    int ansF = 0, ansB = 0;

    for(int i=lp; i<=rp; i++) {
        string s;
        cin >> s;
        if(s == "Fizz") {
            if(!ansF) ansF = i;
            else ansF = __gcd(ansF, i);
        } else if(s == "Buzz") {
            if(!ansB) ansB = i;
            else ansB = __gcd(ansB, i);
        } else if(s == "FizzBuzz") {
            if(!ansF) ansF = i;
            else ansF = __gcd(ansF, i);
            if(!ansB) ansB = i;
            else ansB = __gcd(ansB, i);
        }
    }

    if(!ansF) cout << rp+1 << " ";
    else cout << ansF << " ";
    if(!ansB) cout << rp+2 << '\n';
    else cout << ansB << '\n';
    return 0;
}