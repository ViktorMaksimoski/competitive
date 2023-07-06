#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    if(name != "") setUSA(name);
}

int main() {
    setIO();

    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    vector<int> occ(2, 0);
    int i=0, j=0;
    while(j < n) {
        occ[v[j]]++;

        while(occ[0] > k)
            occ[v[i]]--, i++;

        ans = max(ans, j - i + 1);
        j++;
    }

    cout << ans << '\n';
    return 0;
}