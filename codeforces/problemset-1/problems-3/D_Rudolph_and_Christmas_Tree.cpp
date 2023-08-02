#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define pii pair<int, int>
#define pll pair<long long, long long>
#define debug(x) cout << #x << " = " << x << endl
#define pb push_back
#define eb emplace_back
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve() {
    ull n, d, h;
    cin >> n >> d >> h;

    vector<ull> v(n);
    for(ull &x : v) cin >> x;

    ld ans = 0;


    reverse(all(v));
    ull last = INT_MAX;
    for(int i=0; i<n; i++) {
        if(v[i] == last) continue;
        ld area = (long double)(d*h) / 2;
        if(last >= v[i] + h) {
            ans += area;
            last = v[i];
            continue;
        } else {
            ull hDiff = (v[i] + h) - last;
            ld sim = (long double)(h) / hDiff;
            ld newArea = (long double)(area) / (sim*sim);
            
            ans += area;
            ans -= newArea;
            last = v[i];
            continue;
        }
    }

    cout << setprecision(7) << fixed << ans << '\n';
}

int main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve(); 

    return 0;
}