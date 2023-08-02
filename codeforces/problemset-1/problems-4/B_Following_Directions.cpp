#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        int x=0, y=0;
        bool ok = false;

        for(char &ch : s) {
            if(ch == 'U') y++;
            else if(ch == 'D') y--;
            else if(ch == 'R') x++;
            else if(ch == 'L') x--;

            if(x == 1 && y == 1) ok = 1;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}