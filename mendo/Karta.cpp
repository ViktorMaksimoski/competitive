#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int LOG = 20;
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

    string s;
    double ans = 0;
    int x=0, y=0;
    getline(cin, s);

    for(int i=0; i<s.size()-1; i++) {
        if(s[i] == 'e' || s[i] == 's' || s[i] == 'w' || s[i] == 'n') {
            int num = 0;

            if(s[i+1] >= '0' && s[i+1] <= '9') 
                num += (s[i+1] - '0');
            if(i < s.size()-2 && s[i+2] >= '0' && s[i+2] <= '9')
                num *= 10, num += (s[i+2] - '0');

            if(s[i] == 'w') x -= num;
            else if(s[i] == 'e') x += num;
            else if(s[i] == 'n') y += num;
            else y -= num;

            //cout << s[i] << ": " << num << '\n';
        }
    }
    //cout << x << " - " << y << endl;
    ans = sqrt(x*x + y*y);
    cout << setprecision(2) << fixed << ans << '\n';
    return 0;
}