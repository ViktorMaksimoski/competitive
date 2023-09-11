#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define int long long

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

struct CHT {
    struct Line {
        ll a, b;
        Line(ll x, ll y) : a(x), b(y) {}

        ll val(ll x) {
            return a * x + b;
        }

        ll intersect(Line y) {
            return (y.b - b + a - y.a) / (a - y.a);
        };
    };

    deque<pair<Line, ll> > q;

    void insert(ll a, ll b) {
        Line line(a, b);
        while(q.size() > 0 && q.back().second >= q.back().first.intersect(line)) 
            q.pop_back();

        if(!q.size()) {
            q.push_back({ line, 0 });
            return ;
        }

        q.push_back({ line, q.back().first.intersect(line) });
    }

    ll query(ll x) {
        while(q.size() > 1) {
            if(q[1].second <= x) q.pop_front();
            else break;
        }

        return q.front().first.val(x);
    }
};

int32_t main() {
    setIO();

    int n, c;
    cin >> n >> c;

    ll h[n];
    for(int i=0; i<n; i++) cin >> h[i];

    CHT cht;
    ll dp[n];
    dp[0] = 0;

    cht.insert(-2 * h[0], h[0] * h[0] + dp[0]);
    for(int i=1; i<n; i++) {
        dp[i] = cht.query(h[i]) + c + h[i] * h[i];
        cht.insert(-2 * h[i], h[i] * h[i] + dp[i]);
    }
    
    cout << dp[n-1] << '\n';
    return 0;
}