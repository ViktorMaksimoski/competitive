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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct DSU {
    map<string, string> par;
    map<string, int> size;

    string find(string x) {
        if(!par.count(x)) par[x] = x;
        if(!size.count(x)) size[x] = 1;
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    int getSize(string x) {
        x = find(x);
        return size[x];
    }

    bool uni(string a, string b) {
        a = find(a);
        b = find(b);

        if(a == b) return 0;
        if(size[a] < size[b]) swap(a, b);

        size[a] += size[b];
        par[b] = a;

        return 1;
    }
};

void solve() {
    int n;
    cin >> n;

    DSU dsu;

    for(int i=0; i<n; i++) {
        string a, b;
        cin >> a >> b;
        dsu.uni(a, b);
        cout << dsu.getSize(a) << '\n';
    }
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}