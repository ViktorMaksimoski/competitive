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

    set<int> big, small, ndecide;

    for(int i=0; i<3; i++) {
        set<int> left, right;
        char ch;
        for(int j=0; j<4; j++) {
            int x;
            cin >> x;
            left.insert(x);
        }
        cin >> ch;
        for(int j=0; j<4; j++) {
            int x;
            cin >> x;
            right.insert(x);
        }

        if(ch == '>') {
            for(int i=1; i<=12; i++) {
                if(!left.count(i) && !right.count(i)) {
                    ndecide.insert(i);
                    small.erase(i);
                    big.erase(i);
                }
            }

            for(const int &x : left) {
                if(small.count(x)) {
                    small.erase(x);
                    big.erase(x);
                    ndecide.insert(x);
                } else big.insert(x);
            }

            for(const int &x : right) {
                if(big.count(x)) {
                    small.erase(x);
                    big.erase(x);
                    ndecide.insert(x);
                } else small.insert(x);
            }
            
        } else if(ch == '<') {
            for(int i=1; i<=12; i++) {
                if(!left.count(i) && !right.count(i)) {
                    ndecide.insert(i);
                    small.erase(i);
                    big.erase(i);
                }
            }

            for(const int &x : left) {
                if(big.count(x)) {
                    small.erase(x);
                    big.erase(x);
                    ndecide.insert(x);
                } else small.insert(x);
            }

            for(const int &x : right) {
                if(small.count(x)) {
                    small.erase(x);
                    big.erase(x);
                    ndecide.insert(x);
                } else big.insert(x);
            }
            
        } else if(ch == '=') {
            for(const int &x : left) ndecide.insert(x), small.erase(x), big.erase(x);
            for(const int &x : right) ndecide.insert(x), small.erase(x), big.erase(x);
        }
    }

    for(const int &x : big)
        if(ndecide.count(x))
            big.erase(x);

    for(const int &x : small)
        if(ndecide.count(x))
            small.erase(x);

    if(big.size() + small.size() > 1) cout << "indefinite\n";
    else if(big.size() == 1 && !small.size()) cout << *big.begin() << "+" << '\n';
    else if(!big.size() && small.size() == 1) cout << *small.begin() << "-" << '\n';
    else cout << "impossible\n";
    return 0;
}