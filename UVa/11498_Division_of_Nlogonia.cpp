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

int32_t main() {
    setIO();

    int n;

    while(true) {
        cin >> n;
        if(n == 0) break;

        int dx, dy;
        cin >> dx >> dy;

        for(int i=0; i<n; i++) {
            int x, y;
            cin >> x >> y;

            if(x == dx || y == dy) {
                cout << "divisa\n";
                continue;
            }

            if(x < dx && y < dy) {
                cout << "SO\n";
                continue;
            }

            if(x < dx && y > dy) {
                cout << "NO\n";
                continue;
            }

            if(x > dx && y < dy) {
                cout << "SE\n";
                continue;
            }

            if(x > dx && y > dy) {
                cout << "NE\n";
                continue;
            }
        }
    }

    return 0;
}