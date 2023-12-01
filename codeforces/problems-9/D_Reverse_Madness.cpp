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

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> l(k), r(k);
    for(int &x : l) cin >> x, x--;
    for(int &x : r) cin >> x, x--;

    int q;
    cin >> q;
    vector<int> to_swap(n);

    for(int i=0; i<q; i++) {
        int x;
        cin >> x;
        to_swap[x-1]++;
    }

    for(int i=0; i<k; i++) {
        int lp = l[i], rp = r[i], total = 0;
        for(int j=lp; j<=rp; j++) {
            if(2*j > lp + rp) break;
            total += to_swap[j] + to_swap[rp-j+lp];
            //cout << j << ": " << total << '\n';
            if(total % 2 == 1) {
                char temp = s[j];
                s[j] = s[rp-j+lp];
                s[rp-j+lp] = temp;
            } 
        }
    }

    cout << s << '\n';
}

int32_t main() {
    setIO();

    int t = 1;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}