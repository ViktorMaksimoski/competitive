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

int min_div = 1e9;

int toInt(string s) {
    int ans = 0;

    for(char &ch : s) {
        ans *= 10;
        ans += (ch - '0');
    }

    return ans;
}

int countDivs(string s) {
    int n = toInt(s);
    int ans = 0;
    
    for(int i=1; i*i<=n; i++) {
        if(n % i > 0) continue;
        ans++;
        if(i * i != n) ans++;
    }

    return ans;
}

int32_t main() {
    setIO();

    int n;
    cin >> n;
    
    string s = "";
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        s += (x + '0');
    }

    sort(all(s));
    map<int, vector<string> > by_div;

    do {
        int divs = countDivs(s);
        min_div = min(min_div, divs);
        by_div[divs].push_back(s);
    } while(next_permutation(all(s)));

    cout << min_div << '\n';
    for(string &x : by_div[min_div]) 
        cout << x << " ";
    return 0;
}