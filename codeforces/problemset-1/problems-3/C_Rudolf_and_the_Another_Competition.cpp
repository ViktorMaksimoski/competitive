#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define pii pair<int, int>
#define pll pair<long long, long long>
#define debug(x) cout << #x << " = " << x << endl
#define pb push_back
#define eb emplace_back
#define int long long
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

struct Res {
    int id;
    int points;
    ll penalty;
};

bool cmp(Res &a, Res &b) {
    if(a.points == b.points)
        return (a.penalty < b.penalty);
    return (a.points > b.points);
}

void solve() {
    int n,m,h;
    cin >> n >> m >> h;

    vector<vector<int> > mat(n, vector<int>(m, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> mat[i][j];

    vector<Res> res;
    for(int i=0; i<n; i++) {
        sort(all(mat[i]));
        int points = 0;
        ll total = 0;
        ll penalty = 0;

        int j=0;
        while(total <= h && j < m) {
            if(total + mat[i][j] <= h) {
                total += mat[i][j];
                points++;
                penalty += total;
            }
            j++;
        }

        res.pb(Res{i+1, points, penalty});
    }

    sort(all(res), cmp);
    for(int i=0; i<sz(res); i++) {
        if(res[i].id == 1) {
            //cout << res[i].id << " " << res[i].points << '\n';
            cout << i+1 << '\n';
            return ;
        }
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