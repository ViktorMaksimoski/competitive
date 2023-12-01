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

int32_t main() {
    setIO();

    int n, S;
    cin >> n >> S;

    vector<int> v(n);
    vector<vector<int> > table(n+1, vector<int>(20, 0));
    for(int i=0; i<n; i++) cin >> v[i], table[i][0] = v[i]; 

    for(int k=1; k<20; k++)
        for(int i=0; i+(1<<k)-1<n; i++)
            table[i][k] = max(table[i][k-1], table[i+(1<<(k-1))][k-1]);

    auto query = [&](int a, int b) {
        int len = b-a+1;
        int k=0;
        while((1 << (k+1)) <= len) k++;

        return max(
            table[a][k],
            table[b-(1<<k)+1][k]
        );
    };

    int len=0, pos=0, mxh=0;
    int i=0, j=0;
    ll total = 0;

    while(j < n) {
        total += v[j];

        while(query(i, j) * (j - i + 1) - total > S && i < j) {
            total -= v[i];
            i++;
        }

        if(query(i, j) * (j - i + 1) - total == S) {
            if(j - i + 1 > len) {
                len = j - i + 1;
                mxh = query(i, j);
                pos = i;
            } else if(j - i + 1 == len && query(i, j) > mxh) {
                mxh = query(i, j);
                pos = i;
            }
        }

        j++;
    }

    cout << len << " " << pos+1 << '\n';
    return 0;
}