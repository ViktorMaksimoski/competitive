#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define int long long

using namespace std;
using ll = long long;

const int maxn = 1e5+5;

string a, b;
int n;
int prefix[3][3][maxn+1];

inline int32_t getHash(char &ch) {
    if(ch == 'A') return 0;
    if(ch == 'C') return 1;
    return 2;
}

void init(string x, string y) {
    a = x;
    b = y;
    n = sz(a);

   for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
        for(int k=0; k<n; k++)
            prefix[i][j][k+1] = prefix[i][j][k] + (getHash(a[k]) == i && getHash(b[k]) == j);
}

int32_t get_distance(int32_t x, int32_t y) {
    for(int i=0; i<3; i++) {
        int cnt1=0, cnt2=0;

        for(int j=0; j<3; j++) {
            cnt1 += prefix[i][j][y+1] - prefix[i][j][x];
            cnt2 += prefix[j][i][y+1] - prefix[j][i][x];
        }

        if(cnt1 != cnt2) return -1;
    }

    int ans1 = 0, ans2 = 0;

    int v[3][3];
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            v[i][j] = prefix[i][j][y+1] - prefix[i][j][x];

    for(int i=0; i<3; i++) {
        for(int j=i+1; j<3; j++) {
            if(v[i][j] < v[j][i]) swap(v[i][j], v[j][i]);
            ans2 += v[i][j] - v[j][i];
            ans1 += v[j][i];
        }
    }

    return ans1 + ans2 / 3 * 2;
}

// int32_t main() {
//     int n, q;
//     cin >> n >> q;

//     string x, y;
//     cin >> x >> y;

//     init(x, y);
    
//     while(q--) {
//         int l, r;
//         cin >> l >> r;
//         cout << get_distance(l, r) << '\n';
//     }
//     return 0;
// }