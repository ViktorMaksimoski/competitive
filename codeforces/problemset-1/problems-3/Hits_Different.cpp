#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    if(name != "") setUSA(name);
}



int main() {
    setIO();

    int t;
    cin >> t;
    
    vector<ull> ans(int(5*1e6), 0);
    vector<vector<ull> > prefix(2024, vector<ull>(2024, 0));

    ll c = 1;
    for(int i=1; i<2024; i++) {
        for(int j=i-1; j>0; j--) {
            int row = j;
            int col = i - j;

            prefix[row][col] = c * c;
            prefix[row][col] += prefix[row-1][col];
            prefix[row][col] += prefix[row][col-1];
            prefix[row][col] -= prefix[row-1][col-1];

            ans[c++] = prefix[row][col];
        }
    }

    while(t--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }

    return 0;
}