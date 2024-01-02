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

int n, m;
int rsk;
vector<pii> v;

vector<int> get(int x, int y) {
    map<int, vector<int> > by_dist;

    for(int i=0; i<rsk; i++)
        by_dist[abs(x-v[i].first)+abs(y-v[i].second)].push_back(i);

    return by_dist.begin()->second;
}

int f(int x1, int y1, int x2, int y2) {
    if(get(x1, y1) == get(x2, y2) && get(x1, y1) == get(x2, y1) && get(x1, y1) == get(x1, y2)) {
        if(get(x1, y1).size() == 1) return 0;
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }

    if(x1 == x2 && y1 == y2 && x1 == y1) return 0;
    if(x2 < x1 || y2 < y1) return 0;
    
    int xm = (x1 + x2) / 2;
    int ym = (y1 + y2) / 2;
    
    return f(x1, y1, xm, ym) + f(x1, ym+1, xm, y2) + f(xm+1, y1, x2, ym) + f(xm+1, ym+1, x2, y2);
}

int32_t main() {
    setIO();

    cin >> n >> m >> rsk;
    v.resize(rsk);

    for(auto &x : v) {
        cin >> x.first >> x.second;
        x.first--, x.second--;
    }

    cout << f(0, 0, n-1, m-1) << '\n';
    return 0;
}