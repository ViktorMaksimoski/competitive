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

int32_t main() {
    setIO();

    int a, b;
    cin >> a >> b;
    int ans = 0;

    vector<int> digA, digB;
    while(a) {
        digA.push_back(a%10);
        a /= 10;
    }

    while(b) {
        digB.push_back(b%10);
        b /= 10;
    }

    while(sz(digA) < sz(digB)) digA.push_back(0);
    while(sz(digA) > sz(digB)) digB.push_back(0);

    int i=0;
    vector<int> add(sz(digA), 0);
    while(i < sz(digA)) {
        int sum = digA[i] + digB[i] + add[i];

        if(sum >= 10) {
            if(i == sz(digA) - 1) {
                add.push_back(sum / 10);
                digA.push_back(0);
                digB.push_back(0);
            } else {
                add[i+1] = sum / 10;
            }
            ans++;
        }

        i++;
    }

    // for(int &x : add) cout << x << " ";
    // cout << '\n';
    // cout << "-------\n";
    // for(int &x : digA) cout << x << " ";
    // cout << '\n';
    // for(int &x : digB) cout << x << " ";
    // cout << '\n';

    cout << ans << '\n';
    return 0;
}