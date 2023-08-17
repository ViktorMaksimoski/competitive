#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
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
    cin >> n;

    vector<int> d(n);
    for(int &x : d) cin >> x;

    int visTime[3][n];
    int startTime[3][n][n];
    int endTime[3][n][n];
    for(int i=0; i<3; i++)
        for(int j=0; j<n; j++)
            cin >> visTime[i][j];

    for(int i=0; i<3; i++) {
        for(int j=0; j<n; j++) {
            int total = 0;

            for(int k=0; k<n; k++) {
                startTime[i][j][(j + k) % n] = total;
                total += visTime[i][(j + k) % n];
                endTime[i][j][(j + k) % n] = total;
                total += d[(j + k) % n];
            }
        }
    }

    bool good[3][3][n][n];
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            for(int k=0; k<n; k++) {
                for(int x=0; x<n; x++) {
                    good[i][j][k][x] = true;
                    for(int pos=0; pos<n; pos++) {
                        if(endTime[i][k][pos] > startTime[j][x][pos] && endTime[j][x][pos] > startTime[i][k][pos])
                            good[i][j][k][x] = false;
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                if(good[0][1][i][j] && good[0][2][i][k] && good[1][2][j][k]) {
                    cout << i + 1 << " " << j + 1 << " " << k + 1 << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "impossible\n";
    return 0;
}