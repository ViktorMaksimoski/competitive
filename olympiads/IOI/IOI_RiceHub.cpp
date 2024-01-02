#include <bits/stdc++.h>
//#include "ricehub.h"

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

int besthub(int R, int L, int a[], ll B) {
    int ans = 0;

    vector<int> v(R+1);
    vector<ll> pref(R+1);    
    for(int i=0; i<R; i++) {
        v[i+1] = a[i];
        pref[i+1] = a[i] + pref[i];
    }

    auto query = [&](int l, int r) {
        return pref[r] - pref[l-1];
    };

    for(int i=1; i<=R; i++) {
        int l=i, r=R;
        while(l <= r) {
            int j = (l + r) / 2;
            int mid = (i + j) / 2;
            ll total = ((mid - i) * v[mid] - query(i, mid-1)) + (query(mid+1, j) - (j - mid) * v[mid]);

            if(total <= B) ans = max(ans, j - i + 1), l = j + 1;
            else r = j - 1;
        }
    }

    return ans;
}

// int32_t main() {
//     setIO();

//     int R, L;
//     ll B;
//     cin >> R >> L >> B;

//     int v[R];
//     for(int i=0; i<R; i++) cin >> v[i];

//     cout << besthub(R, L, v, B) << '\n';
//     return 0;
// }