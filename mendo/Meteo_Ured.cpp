#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair
#define int long long

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

multiset<int> small, big;
void insert(int val, int k) {
    int leftBest = *(--small.end());
    if(leftBest < val) {
        big.insert(val);
        if(big.size() > k/2) {
            small.insert(*big.begin());
            big.erase(big.find(*big.begin()));
        }
    } else {
        small.insert(val);
        if(small.size() > (k+1)/2) {
            big.insert(*(--small.end()));
            small.erase(small.find(*(--small.end())));
        }
    }
}
 
void erase(int val, int k) {
    if(small.find(val) != small.end()) small.erase(small.find(val));
    else big.erase(big.find(val));
 
    if(small.empty()) {
        small.insert(*big.begin());
        big.erase(big.find(*big.begin()));
        
    }
}

int32_t main() {
    setIO();

    int s, m, a, n, k;
    cin >> s >> m >> a >> n >> k;

    ll ans = 0;
    vector<int> v(n);
    v[0] = s;
    for(int i=1; i<n; i++)
        v[i] = (v[i-1] * m + a) % 65536;

    small.insert(v[0]);
    for(int i=1; i<k; i++)
        insert(v[i], k);
    ans += *small.rbegin();

    for(int i=k; i<n; i++) {
        if(k == 1) {
            insert(v[i], k);
            erase(v[i-k], k);
        } else {
            erase(v[i-k], k);
            insert(v[i], k);
        }
        ans += *small.rbegin();
    }

    cout << ans << '\n';
    return 0;
}