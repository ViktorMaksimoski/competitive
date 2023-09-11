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

struct Rect { int x1, y1, x2, y2; };

int32_t main() {
    setIO();

    int n;
    cin >> n;

    vector<Rect> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i].x1;
        cin >> v[i].y1;
        int w, h;
        cin >> w >> h;
        v[i].x2 = v[i].x1 + h - 1;
        v[i].y2 = v[i].y1 + w - 1;
    }

    int px, py;
    cin >> px >> py;
    int ans = -1;

    for(int i=0; i<n; i++) {
        if(px < v[i].x1) continue;
        if(px > v[i].x2) continue;
        if(py < v[i].y1) continue;
        if(py > v[i].y2) continue;
        ans = i + 1;
    }

    //cout << ans << '\n';
    if(ans >= 1)
        cout << "prozorec " << ans << '\n';
    else
        cout << "pozadina\n"; 
    return 0;
}