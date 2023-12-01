#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

vector<pii> factorize(int n, int k) {
    vector<pii> res;
    map<int, int> occ;
    
    for(int i=2; i*i<=n; i++) {
        int cnt = 0;
        while(n % i == 0) {
            cnt++;
            n /= i;
        }

        occ[i] += cnt;
    }

    if(n > 1) occ[n]++;

    for(auto &x : occ)
        if(x.second % k > 0)
            res.push_back({ x.first, x.second % k });
    
    return res;
}

vector<pii> complement(vector<pii> &v, int k) {
    vector<pii> res;

    for(pii &x : v)
        if(x.second % k > 0)
            res.push_back({ x.first, k - x.second });

    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    ll ans = 0;

    map<vector<pii>, int> factorOcc;
    vector<int> v(n);

    for(int &x : v) {
        cin >> x;
        factorOcc[factorize(x, k)]++;
    }

    for(int &x : v) {
        vector<pii> fac = factorize(x, k);
        vector<pii> comp = complement(fac, k);
        ans += factorOcc[comp];
        ans -= (fac == comp);
    }

    cout << ans / 2 << '\n';
    return 0;
}