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

ll exp(int a, int b) {
    ll ans = 1;
    for(int i=0; i<b; i++) ans *= a;
    return ans;
}

int32_t main() {
    setIO();

    ll m;
    int k, cnt7 = 0;
    cin >> m >> k;
    m++;

    string n = to_string(m);
    reverse(all(n));

    for(char &ch : n)
        if(ch == '7') cnt7++;

    int i=0;
    while(i < n.size() && cnt7 < k) {
        if(n[i] < '7') {
            n[i] = '7';
            cnt7++;
            for(int j=0; j<i; j++) {
                if(n[j] != '7') {
                    if(cnt7 < k) {
                        n[j] = '7';
                        cnt7++;
                    } else n[j] = '0';
                }
            }
            i++;
        } else if(n[i] > '7') {
            reverse(all(n));

            m = stoll(n) + exp(10, i);
            n = to_string(m);
            reverse(all(n));

            cnt7 = 0;
            for(char &ch : n)
                if(ch == '7') cnt7++;

            i = 0;
        } else i++;
    }

    while(cnt7 < k) {
        n += '7';
        cnt7++;
    }

    reverse(all(n));
    cout << n << '\n';
    return 0;
}