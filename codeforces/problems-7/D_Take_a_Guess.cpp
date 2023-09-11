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

int askOR(int a, int b) {
    cout << "or " << a << " " << b << endl;
    int ans = 0;
    cin >> ans;
    return ans;
}

int askAND(int a, int b) {
    cout << "and " << a << " " << b << endl;
    int ans = 0;
    cin >> ans;
    return ans;
}

ll getSum(int a, int b) {
    return askOR(a, b) + askAND(a, b);
}

int32_t main() {
    setIO();

    int n, k;
    cin >> n >> k;

    vector<ll> v(n);

    ll ab = getSum(1, 2);
    ll bc = getSum(2, 3);
    ll ac = getSum(1, 3);
    ll abc = (ab + bc + ac) / 2;

    v[0] = abc - bc;
    v[1] = abc - ac;
    v[2] = abc - ab;

    for(int i=3; i<n; i++) {
        ll res = getSum(1, i+1);
        v[i] = res - v[0];
    }

    sort(all(v));
    cout << "finish " << v[k-1] << endl;
    return 0;
}