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
    char mat[3][3];
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++) cin >> mat[i][j];

    for(int i=0; i<3; i++) {
        if(mat[i][0] == 'X' && mat[i][1] == 'X' && mat[i][2] == 'X') {
            cout << "X\n";
            return ;
        }

        if(mat[i][0] == 'O' && mat[i][1] == 'O' && mat[i][2] == 'O') {
            cout << "O\n";
            return ;
        }

        if(mat[i][0] == '+' && mat[i][1] == '+' && mat[i][2] == '+') {
            cout << "+\n";
            return ;
        }
    }

    for(int i=0; i<3; i++) {
        if(mat[0][i] == 'X' && mat[1][i] == 'X' && mat[2][i] == 'X') {
            cout << "X\n";
            return ;
        }

        if(mat[0][i] == 'O' && mat[1][i] == 'O' && mat[2][i] == 'O') {
            cout << "O\n";
            return ;
        }

        if(mat[0][i] == '+' && mat[1][i] == '+' && mat[2][i] == '+') {
            cout << "+\n";
            return ;
        }
    }


    if(mat[0][0] == 'X' && mat[1][1] == 'X' && mat[2][2] == 'X') {
        cout << "X\n";
        return ;
    }

    if(mat[0][0] == 'O' && mat[1][1] == 'O' && mat[2][2] == 'O') {
        cout << "O\n";
        return ;
    }

    if(mat[0][0] == '+' && mat[1][1] == '+' && mat[2][2] == '+') {
        cout << "+\n";
        return ;
    }

    if(mat[2][0] == 'X' && mat[1][1] == 'X' && mat[0][2] == 'X') {
        cout << "X\n";
        return ;
    }

    if(mat[2][0] == 'O' && mat[1][1] == 'O' && mat[0][2] == 'O') {
        cout << "O\n";
        return ;
    }

    if(mat[2][0] == '+' && mat[1][1] == '+' && mat[0][2] == '+') {
        cout << "+\n";
        return ;
    }

    cout << "DRAW\n";
}

int main() {
    setIO();

   int t;
   cin >> t;
   
   while(t--)
    solve();

    return 0;
}